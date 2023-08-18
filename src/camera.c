#include <gb/gb.h>
#include <gbdk/platform.h>
#include <gbdk/incbin.h>
#include <gbdk/metasprites.h>
#include <stdint.h>
#include <stdbool.h>

#include "global.h"
#include "levellist.h"
#include "../res/spritemaps.h"

//how far does the player go before camera moves?
#define camera_bound_left 72
#define camera_bound_right 73

//resolution of screen
#define horizontalresolution 160
#define verticalresolution 144

#define MIN(A,B) ((A)<(B)?(A):(B))

void camera(void) NONBANKED {
	_saved_bank = CURRENT_BANK;
	//prevent player from going out of bounds
	if(player_sprite_X < 0){
		player_sprite_X = 0;
	}else if(player_sprite_X > (current_level->map_width << 3) - 16){
		player_sprite_X = (current_level->map_width << 3) - 16;
	}
	
	//player map position
	int16_t player_sprite_Xmap = player_sprite_X;
	int16_t player_sprite_Ymap = player_sprite_Y;
	
	//player screen position
	int16_t player_sprite_Xscr = player_sprite_Xmap - cameraX;
	int16_t player_sprite_Yscr = player_sprite_Ymap - cameraY;
	
	//calculate new camera position
	if(player_sprite_Xscr > camera_bound_right){
		newcameraX = player_sprite_Xmap - camera_bound_right;
	}else if(player_sprite_Xscr < camera_bound_left){
		newcameraX = player_sprite_Xmap - camera_bound_left;
	}else{
		newcameraX = cameraX;
	}
	
	//check if camera is out of bounds
	if(newcameraX < 0){
		newcameraX = 0;
	}else if(newcameraX > (current_level->map_width << 3) - horizontalresolution){
		newcameraX = (current_level->map_width << 3) - horizontalresolution;
	}
	
	SWITCH_ROM(current_level->bank_tile);
	//check if part of a new tilemap needs to be uploaded
	map_pos_x = (uint8_t)(newcameraX >> 3u);
	if (map_pos_x != old_map_pos_x) {
			if (newcameraX < cameraX) {
					set_bkg_submap(map_pos_x, 0, 1, MIN(19u, current_level->map_height), current_level->tile_maps, current_level->map_width);     
			} else {
					if ((current_level->map_width - 20u) > map_pos_x) set_bkg_submap(map_pos_x + 20u, 0, 1, MIN(19u, current_level->map_height), current_level->tile_maps, current_level->map_width);     
			}
			old_map_pos_x = map_pos_x;
	}
	
	//check if camera moved
	if(cameraX != newcameraX){
		cameraX = newcameraX;
	}
	
	//draw player sprite position
	
	/*
	move_sprite(0, player_sprite_X   -newcameraX, player_sprite_Y+   player_tile_y_offset[0]);
	move_sprite(1, player_sprite_X+8 -newcameraX, player_sprite_Y+   player_tile_y_offset[1]);
	move_sprite(2, player_sprite_X+16-newcameraX, player_sprite_Y+   player_tile_y_offset[2]);
	move_sprite(3, player_sprite_X+24-newcameraX, player_sprite_Y+   player_tile_y_offset[3]);
	move_sprite(4, player_sprite_X   -newcameraX, player_sprite_Y+16+player_tile_y_offset[4]);
	move_sprite(5, player_sprite_X+8 -newcameraX, player_sprite_Y+16+player_tile_y_offset[5]);
	move_sprite(6, player_sprite_X+16-newcameraX, player_sprite_Y+16+player_tile_y_offset[6]);
	move_sprite(7, player_sprite_X+24-newcameraX, player_sprite_Y+16+player_tile_y_offset[7]);
	*/
	
	SWITCH_ROM(BANK(playermeta));
	
	if ((dub_buffer_counter & 1) == 0) {
		move_metasprite_ex(playermeta[0], 0, 0, 0, player_sprite_X - newcameraX, player_sprite_Y);
	} else {
		move_metasprite_ex(playermeta[1], 0, 0, 0, player_sprite_X - newcameraX, player_sprite_Y);
	}
	
	//draw enemy sprite position
	/* move_sprite(8 , enemy_sprite_X  -newcameraX, enemy_sprite_Y   +enemy_tile_y_offset[0]);
	move_sprite(9 , enemy_sprite_X+8-newcameraX, enemy_sprite_Y   +enemy_tile_y_offset[0]);
	move_sprite(10, enemy_sprite_X  -newcameraX, enemy_sprite_Y+16+enemy_tile_y_offset[0]);
	move_sprite(11, enemy_sprite_X+8-newcameraX, enemy_sprite_Y+16+enemy_tile_y_offset[0]); */
	
	if (enemy_present && (enemy_sprite_X-newcameraX) < horizontalresolution && (enemy_sprite_X-newcameraX+16) > 0) {
		move_metasprite_ex(zombiemeta[enemy_frame_num], 32, 0, 8, enemy_sprite_X - newcameraX, enemy_sprite_Y);
	} else {
		hide_metasprite(zombiemeta[enemy_frame_num], 8);
	}
	
	SWITCH_ROM(_saved_bank);
}