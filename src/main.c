#include <gb/gb.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/incbin.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <types.h>

#include "../res/greyscale.h"

#define CGB_BKG_PAL_0 0u
#define CGB_ONE_PAL   1u

const palette_color_t cgb_pal_black[] = {RGB_BLACK, RGB_BLACK, RGB_BLACK, RGB_BLACK};

//spritemaps
#include "../res/spritemaps.h"

//background test tiles
INCBIN(testbgset, "res/str3tset.2bpp")

//comic book font
INCBIN(comicfont, "res/comic8x8.2bpp")
INCBIN(healthfont, "res/healthbar8x8.2bpp")

//failed background test tilemap
//INCBIN(testbgmap, "level/str3ttestmap.tilemap")

#include "global.h"

//resolution of screen
#define horizontalresolution 160
#define verticalresolution 144

//SGB start

typedef struct sgb_packet_t {
    uint8_t id;
    uint16_t colors[7];
    uint8_t _pad0;
} sgb_packet_t;

const sgb_packet_t PAL01 = {
    (SGB_PAL_01 << 3) | 1,
    {                             
        // palette 0
        RGB(31, 31, 31),  
        RGB(20, 20, 20),  
        RGB( 9,  9,  9),  
        RGB( 0,  0,  0),  
        // palette 1
        RGB(31, 31,  0),  
        RGB( 0, 31, 31),  
        RGB(31,  0, 31)
    },
    0x00
};

//SGB end

uint8_t health_hud_map[10] = {
	240, 241, 
	243, 243, 243, 243, 243, 243, 243, 243
};

uint8_t dead_hud_map[8] = {
	242, 242, 242, 242, 242, 242, 242, 242
};

void handleInputGameplay();
void handleInputMenu(uint8_t menuOptionsTotal);
void camera();
void playerMapCollision(const unsigned char level_num_col[]);
void enemyMapCollision(const unsigned char level_num_col[]);
void setPlayerFrameMap(uint8_t spritemap_index);
void animatePlayer();
void setEnemyFrameMap(unsigned char enemy_frame_map[]);
void zombieLogic();
void scanline_player_graphics_upload();
void vblank_sync_gameplay();
void invincibleFrameCount();
void playerEnemyCollision();
void getHurt();
void gameOver();
void loadLevel();

#include "main.h"
#include "collision.h"
#include "input.h"
#include "camera.h"
#include "animate.h"
#include "../music/hugedriver.h"

//by Arky720 a.k.a. DJArky
int my_strlen(uint8_t TEXT[]);
//modified from code by Arky720 a.k.a. DJArky
void print_text_win(uint8_t xt, uint8_t yt, uint8_t TEXT[]);
//modified from code by Arky720 a.k.a. DJArky
void print_text_bkg(uint8_t xt, uint8_t yt, uint8_t TEXT[]);

void main(void)
{
	//make it greyscale not greenscale
	if (_cpu == CGB_TYPE) {
    set_bkg_palette(0, 1, greyscale);
		set_sprite_palette(0, 1, greyscale);
		set_sprite_palette(1, 1, greyscale);
  }
	if (sgb_check()) {
		for (uint8_t i = 4; i != 0; i--) wait_vbl_done();
		SHOW_BKG; DISPLAY_ON;

    sgb_transfer((void *)&PAL01);
		HIDE_BKG; DISPLAY_OFF;
	}
	
	NR52_REG = 0x80;
	NR51_REG = 0xFF;
	NR50_REG = 0x77;
	
	//turn on lcd display
	DISPLAY_ON;
	
	//all sprites will be tall
	SPRITES_8x16;
	
	while(1){
		if(gamemodec == 0){
			add_VBL(vblank_sync_gameplay);
			add_VBL(hUGE_dosound);
			loadLevel();
			hUGE_init(&hotaya);
			gamemodec = 1;
		}else if (gamemodec == 1){
			handleInputGameplay();
					
			/* //speed limit
			if (player_velocity_Y > 64) player_velocity_Y = 64;
			if (player_velocity_X > 64) player_velocity_X = 64;
			
			//move sprites by velocity
			player_sprite_X += player_velocity_X;
			player_sprite_Y += player_velocity_Y;
			
			// decelerate 
			if (player_velocity_Y >= 0) {
				if (player_velocity_Y) player_velocity_Y--; 
			} else player_velocity_Y ++;
			if (player_velocity_X >= 0) {
				if (player_velocity_X) player_velocity_X--; 
			} else player_velocity_X ++; */
			
			// check player-map collision
			playerMapCollision(current_level->collision_maps);
			
			animatePlayer();
			
			scanline_player_graphics_upload();
			
			if(enemy_present && (enemy_sprite_X-cameraX) < horizontalresolution && (enemy_sprite_X-cameraX) > 0){
				zombieLogic();
				playerEnemyCollision();
			}
			
			// move camera if needed
			camera();
			
			invincibleFrameCount();
		} else if (gamemodec == 2) {
			gameOver();
		} else if (gamemodec == 3) {
			//draw menu cursor
			print_text_bkg(5, 11, " ");
			print_text_bkg(5, 12, " ");
			print_text_bkg(5, 11+menuOption, ">");
			
			//select from 2 options in menu
			handleInputMenu(2);
			
			if (menuOption == 0 && menuConfirm){
				menuConfirm = FALSE;
				gamemodec = 0;
				//wait until next frame
				wait_vbl_done();
				
				if (_cpu == CGB_TYPE) {
						set_bkg_palette(BKGF_CGB_PAL0, CGB_ONE_PAL, greyscale);
				} else {
						BGP_REG = DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK);
				}
			}
		}
		
		// Done processing, yield CPU and wait for start of next frame
    wait_vbl_done();
	}
}

void zombieLogic() {
	if(enemy_move_counter > 0){
		enemy_move_counter--;
	} else if(enemy_move_counter == 0){
		enemy_move_counter=enemy_move_divisor;
		enemy_move_left = TRUE;
		setEnemyFrameMap(zombiewalk1);
		enemyMapCollision(current_level->collision_maps);
	}
}

void vblank_sync_gameplay() {
	move_bkg(newcameraX, 0);
}

void invincibleFrameCount() {
	if(player_invincible_counter != 0){
		player_invincible_counter--;
		if ((dub_buffer_counter & 1) == 1){
			move_sprite(0, 0, 144);
			move_sprite(1, 0, 144);
			move_sprite(2, 0, 144);
			move_sprite(3, 0, 144);
			move_sprite(4, 0, 144);
			move_sprite(5, 0, 144);
			move_sprite(6, 0, 144);
			move_sprite(7, 0, 144);
		}
	}
}

//by Arky720 a.k.a. DJArky
int my_strlen(uint8_t TEXT[]){
	int len=0x00;
	while(TEXT[len]!=0x00&&len<0x90){
		len++;
		if(((TEXT[len]>0x7E||TEXT[len]<0x30)&& TEXT[len]!=0x20&& TEXT[len]!='n')){break;}
	}
	return len;
}

//modified from code by Arky720 a.k.a. DJArky
void print_text_win(uint8_t xt, uint8_t yt, uint8_t TEXT[]){
	
	set_win_based_tiles(xt,yt,my_strlen(TEXT),1,TEXT, 96);
}

//modified from code by Arky720 a.k.a. DJArky
void print_text_bkg(uint8_t xt, uint8_t yt, uint8_t TEXT[]){
	
	set_bkg_based_tiles(xt,yt,my_strlen(TEXT),1,TEXT, 224);
}

void getHurt(){
	player_life--;
	player_invincible_counter = player_invincible_value;
	if (player_life < 8) {
		set_win_tiles(3 + player_life,0,8 - player_life,1,dead_hud_map);
	}
	if (player_life == 0){
		gamemodec = 2;
	}
}

void gameOver(){
	remove_VBL(vblank_sync_gameplay);
	// Set the screen to black via the palettes to hide the image draw
	if (_cpu == CGB_TYPE) {
			set_bkg_palette(BKGF_CGB_PAL0, CGB_ONE_PAL, cgb_pal_black);
	} else {
			BGP_REG = DMG_PALETTE(DMG_BLACK, DMG_BLACK, DMG_BLACK, DMG_BLACK);
	}
	//set background tile data
	set_bkg_data(0,96,comicfont);
	vmemset((int*)0x9800, 0, 1024);
	print_text_bkg(5, 9, "GAME OVER");
	print_text_bkg(7, 11, "Continue");
	print_text_bkg(7, 12, "Quit");
	move_bkg(0, 0);
	
	//hide window and sprites
	HIDE_WIN;
  HIDE_SPRITES;
	
	//wait until next frame
	wait_vbl_done();
	
	if (_cpu == CGB_TYPE) {
			set_bkg_palette(BKGF_CGB_PAL0, CGB_ONE_PAL, greyscale);
	} else {
			BGP_REG = DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK);
	}
	gamemodec = 3;
}

void loadLevel(){
	
	gamemodec = 1;
	
	HIDE_BKG;
	HIDE_SPRITES;
	HIDE_WIN;
	
	current_level = &game_levels[level_num];
	
	player_sprite_X=72;
	player_sprite_Y=0;
	
	player_life = 8;
	
	player_direction = 1;
	
	enemy_sprite_X=192;
	enemy_sprite_Y=72;
	
	gravity = 1;
	
	player_velocity_X=2;
	player_velocity_Y=2;
	
	frame_rate_divisor=6;
	frame_rate_counter=6;
	
	enemy_velocity_X=1;
	enemy_velocity_Y=1;
	
	enemy_move_divisor=2;
	enemy_move_counter=2;
	enemy_present=TRUE;
	
	enemy_direction=0;
	
	//set zombie tile data
	set_sprite_data(32, 44, zombie_tiles);
	//set background tile data
	set_bkg_data(0,128,testbgset);
	
	map_pos_x = map_pos_y = 0; 
  old_map_pos_x = old_map_pos_y = 255;
	
	//set background tilemap
	set_bkg_submap(map_pos_x, map_pos_y, 32, current_level->map_height, current_level->tile_maps, current_level->map_width);
	//set window tile data
	set_win_data(240,4,healthfont);

	//show window, background and sprites
	SHOW_WIN;
	SHOW_BKG;
  SHOW_SPRITES;
	
	move_win(7, 128);
	
	set_win_tiles(1,0,2+player_life,1,health_hud_map);
}