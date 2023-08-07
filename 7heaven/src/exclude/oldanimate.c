#include <gb/gb.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <gbdk/incbin.h>
#include <stdint.h>
#include <stdbool.h>

#include "animate.h"

//spritemaps
#include "../res/spritemaps.h"

#include "global.h"

#define playidleleft    0
#define playwalkleft1   1
#define playwalkleft2   2
#define playwalkleft3   3
#define playwalkleft4   4
#define playattackleft1 5
#define playattackleft2 6
#define playattackleft3 7

#define playidleright     8
#define playwalkright1    9
#define playwalkright2   10
#define playwalkright3   11
#define playwalkright4   12
#define playattackright1 13
#define playattackright2 14
#define playattackright3 15

uint16_t player_tile_locations[8] = {0,0,0,0,0,0,0,0};

void scanline_player_graphics_upload() {
    __asm
		_sprite_tile_dest_addr = 0x8000
		
		scanline_routine_1:
			;set source, destination, and amount of lines to check
			ld de, #_player_tiles
			;ld a, (#_player_tile_locations)
			;add a, d
			;ld d, a
			;ld a, (#_player_tile_locations+1)
			;add a, e
			;ld e, a
			ld a, (#_dub_buffer_counter)
			and #0x01
			jr z, 5$
		4$:
			ld hl, #_sprite_tile_dest_addr+256
			ld c, #0x04
			jr 1$
		5$:
			ld hl, #_sprite_tile_dest_addr          
			ld c, #0x04
		1$:
			;wait for STAT mode 3 by checking the first bit of STAT, if it is not mode 3, check again
			ld a, (_STAT_REG)
			and #STATF_BUSY
			jr z, 1$
			;wait for STAT mode 0 by checking the first bit of STAT, if it is not mode 0, check again
		3$:
			ld a, (_STAT_REG)
			and #STATF_BUSY
			jr nz, 3$
		
		2$:
		.rept 7
			;copy from source tiles to destination
			ld a, (de)
      ld (hl+), a
      inc e
		.endm
			;last copy from source tiles to destination for the tile
			ld a, (de)
      ld (hl+), a
			inc de
			;another line down more to go, if there is more lines left, check h-blank again
			dec c
			jr nz, 1$
		_sprite_tile_dest_addr = _sprite_tile_dest_addr + 32
		
		scanline_routine_2:
			;set source, destination, and amount of lines to check
			ld de, #_player_tiles+32
			;ld a, (#_player_tile_locations)
			;add a, d
			;ld d, a
			;ld a, (#_player_tile_locations+1)
			;add a, e
			;ld e, a
			ld a, (#_dub_buffer_counter)
			and #0x01
			jr z, 5$
		4$:
			ld hl, #_sprite_tile_dest_addr+256
			ld c, #0x04
			jr 1$
		5$:
			ld hl, #_sprite_tile_dest_addr          
			ld c, #0x04
		1$:
			;wait for STAT mode 3 by checking the first bit of STAT, if it is not mode 3, check again
			ld a, (_STAT_REG)
			and #STATF_BUSY
			jr z, 1$
			;wait for STAT mode 0 by checking the first bit of STAT, if it is not mode 0, check again
		3$:
			ld a, (_STAT_REG)
			and #STATF_BUSY
			jr nz, 3$
		
		2$:
		.rept 7
			;copy from source tiles to destination
			ld a, (de)
      ld (hl+), a
      inc e
		.endm
			;last copy from source tiles to destination for the tile
			ld a, (de)
      ld (hl+), a
			inc de
			;another line down more to go, if there is more lines left, check h-blank again
			dec c
			jr nz, 1$
		_sprite_tile_dest_addr = _sprite_tile_dest_addr + 32
		
		scanline_routine_3:
			;set source, destination, and amount of lines to check
			ld de, #_player_tiles+64
			;ld a, (#_player_tile_locations)
			;add a, d
			;ld d, a
			;ld a, (#_player_tile_locations+1)
			;add a, e
			;ld e, a
			ld a, (#_dub_buffer_counter)
			and #0x01
			jr z, 5$
		4$:
			ld hl, #_sprite_tile_dest_addr+256
			ld c, #0x04
			jr 1$
		5$:
			ld hl, #_sprite_tile_dest_addr          
			ld c, #0x04
		1$:
			;wait for STAT mode 3 by checking the first bit of STAT, if it is not mode 3, check again
			ld a, (_STAT_REG)
			and #STATF_BUSY
			jr z, 1$
			;wait for STAT mode 0 by checking the first bit of STAT, if it is not mode 0, check again
		3$:
			ld a, (_STAT_REG)
			and #STATF_BUSY
			jr nz, 3$
		
		2$:
		.rept 7
			;copy from source tiles to destination
			ld a, (de)
      ld (hl+), a
      inc e
		.endm
			;last copy from source tiles to destination for the tile
			ld a, (de)
      ld (hl+), a
			inc de
			;another line down more to go, if there is more lines left, check h-blank again
			dec c
			jr nz, 1$
		_sprite_tile_dest_addr = _sprite_tile_dest_addr + 32
		
		scanline_routine_4:
			;set source, destination, and amount of lines to check
			ld de, #_player_tiles+96
			;ld a, (#_player_tile_locations)
			;add a, d
			;ld d, a
			;ld a, (#_player_tile_locations+1)
			;add a, e
			;ld e, a
			ld a, (#_dub_buffer_counter)
			and #0x01
			jr z, 5$
		4$:
			ld hl, #_sprite_tile_dest_addr+256
			ld c, #0x04
			jr 1$
		5$:
			ld hl, #_sprite_tile_dest_addr          
			ld c, #0x04
		1$:
			;wait for STAT mode 3 by checking the first bit of STAT, if it is not mode 3, check again
			ld a, (_STAT_REG)
			and #STATF_BUSY
			jr z, 1$
			;wait for STAT mode 0 by checking the first bit of STAT, if it is not mode 0, check again
		3$:
			ld a, (_STAT_REG)
			and #STATF_BUSY
			jr nz, 3$
		
		2$:
		.rept 7
			;copy from source tiles to destination
			ld a, (de)
      ld (hl+), a
      inc e
		.endm
			;last copy from source tiles to destination for the tile
			ld a, (de)
      ld (hl+), a
			inc de
			;another line down more to go, if there is more lines left, check h-blank again
			dec c
			jr nz, 1$
		_sprite_tile_dest_addr = _sprite_tile_dest_addr + 32
		
		scanline_routine_5:
			;set source, destination, and amount of lines to check
			ld de, #_player_tiles+128
			;ld a, (#_player_tile_locations)
			;add a, d
			;ld d, a
			;ld a, (#_player_tile_locations+1)
			;add a, e
			;ld e, a
			ld a, (#_dub_buffer_counter)
			and #0x01
			jr z, 5$
		4$:
			ld hl, #_sprite_tile_dest_addr+256
			ld c, #0x04
			jr 1$
		5$:
			ld hl, #_sprite_tile_dest_addr          
			ld c, #0x04
		1$:
			;wait for STAT mode 3 by checking the first bit of STAT, if it is not mode 3, check again
			ld a, (_STAT_REG)
			and #STATF_BUSY
			jr z, 1$
			;wait for STAT mode 0 by checking the first bit of STAT, if it is not mode 0, check again
		3$:
			ld a, (_STAT_REG)
			and #STATF_BUSY
			jr nz, 3$
		
		2$:
		.rept 7
			;copy from source tiles to destination
			ld a, (de)
      ld (hl+), a
      inc e
		.endm
			;last copy from source tiles to destination for the tile
			ld a, (de)
      ld (hl+), a
			inc de
			;another line down more to go, if there is more lines left, check h-blank again
			dec c
			jr nz, 1$
		_sprite_tile_dest_addr = _sprite_tile_dest_addr + 32
		
		scanline_routine_6:
			;set source, destination, and amount of lines to check
			ld de, #_player_tiles+160
			;ld a, (#_player_tile_locations)
			;add a, d
			;ld d, a
			;ld a, (#_player_tile_locations+1)
			;add a, e
			;ld e, a
			ld a, (#_dub_buffer_counter)
			and #0x01
			jr z, 5$
		4$:
			ld hl, #_sprite_tile_dest_addr+256
			ld c, #0x04
			jr 1$
		5$:
			ld hl, #_sprite_tile_dest_addr          
			ld c, #0x04
		1$:
			;wait for STAT mode 3 by checking the first bit of STAT, if it is not mode 3, check again
			ld a, (_STAT_REG)
			and #STATF_BUSY
			jr z, 1$
			;wait for STAT mode 0 by checking the first bit of STAT, if it is not mode 0, check again
		3$:
			ld a, (_STAT_REG)
			and #STATF_BUSY
			jr nz, 3$
		
		2$:
		.rept 7
			;copy from source tiles to destination
			ld a, (de)
      ld (hl+), a
      inc e
		.endm
			;last copy from source tiles to destination for the tile
			ld a, (de)
      ld (hl+), a
			inc de
			;another line down more to go, if there is more lines left, check h-blank again
			dec c
			jr nz, 1$
		_sprite_tile_dest_addr = _sprite_tile_dest_addr + 32
		
		scanline_routine_7:
			;set source, destination, and amount of lines to check
			ld de, #_player_tiles+192
			;ld a, (#_player_tile_locations)
			;add a, d
			;ld d, a
			;ld a, (#_player_tile_locations+1)
			;add a, e
			;ld e, a
			ld a, (#_dub_buffer_counter)
			and #0x01
			jr z, 5$
		4$:
			ld hl, #_sprite_tile_dest_addr+256
			ld c, #0x04
			jr 1$
		5$:
			ld hl, #_sprite_tile_dest_addr          
			ld c, #0x04
		1$:
			;wait for STAT mode 3 by checking the first bit of STAT, if it is not mode 3, check again
			ld a, (_STAT_REG)
			and #STATF_BUSY
			jr z, 1$
			;wait for STAT mode 0 by checking the first bit of STAT, if it is not mode 0, check again
		3$:
			ld a, (_STAT_REG)
			and #STATF_BUSY
			jr nz, 3$
		
		2$:
		.rept 7
			;copy from source tiles to destination
			ld a, (de)
      ld (hl+), a
      inc e
		.endm
			;last copy from source tiles to destination for the tile
			ld a, (de)
      ld (hl+), a
			inc de
			;another line down more to go, if there is more lines left, check h-blank again
			dec c
			jr nz, 1$
		_sprite_tile_dest_addr = _sprite_tile_dest_addr + 32
		
		scanline_routine_8:
			;set source, destination, and amount of lines to check
			ld de, #_player_tiles+224
			;ld a, (#_player_tile_locations)
			;add a, d
			;ld d, a
			;ld a, (#_player_tile_locations+1)
			;add a, e
			;ld e, a
			ld a, (#_dub_buffer_counter)
			and #0x01
			jr z, 5$
		4$:
			ld hl, #_sprite_tile_dest_addr+256
			ld c, #0x04
			jr 1$
		5$:
			ld hl, #_sprite_tile_dest_addr          
			ld c, #0x04
		1$:
			;wait for STAT mode 3 by checking the first bit of STAT, if it is not mode 3, check again
			ld a, (_STAT_REG)
			and #STATF_BUSY
			jr z, 1$
			;wait for STAT mode 0 by checking the first bit of STAT, if it is not mode 0, check again
		3$:
			ld a, (_STAT_REG)
			and #STATF_BUSY
			jr nz, 3$
		
		2$:
		.rept 7
			;copy from source tiles to destination
			ld a, (de)
      ld (hl+), a
      inc e
		.endm
			;last copy from source tiles to destination for the tile
			ld a, (de)
      ld (hl+), a
			inc de
			;another line down more to go, if there is more lines left, check h-blank again
			dec c
			jr nz, 1$
		_sprite_tile_dest_addr = _sprite_tile_dest_addr + 32
		__endasm;
}

void setPlayerFrameMap(uint8_t spritemap_index) {
	//player sprite graphics
	//double buffer when uploading player sprite tiles from a spritemap list
	if ((dub_buffer_counter & 1) == 0) {
		for (uint8_t i = 0; i < 8; i++) {
			player_tile_locations[i]=(smtilesources[(spritemap_index<<3)+i]<<4);
		}
		set_sprite_tile(0,  0);
		set_sprite_tile(1,  2);
		set_sprite_tile(2,  4);
		set_sprite_tile(3,  6);
		set_sprite_tile(4,  8);
		set_sprite_tile(5, 10);
		set_sprite_tile(6, 12);
		set_sprite_tile(7, 14);
	} else {
		for (uint8_t i = 0; i < 8; i++) {
			player_tile_locations[i]=(smtilesources[(spritemap_index<<3)+i]<<4);
		}
		set_sprite_tile(0, 16);
		set_sprite_tile(1, 18);
		set_sprite_tile(2, 20);
		set_sprite_tile(3, 22);
		set_sprite_tile(4, 24);
		set_sprite_tile(5, 26);
		set_sprite_tile(6, 28);
		set_sprite_tile(7, 30);
	}
	
	//offset sprites within the player metasprite to save more tiles
	for (uint8_t i = 0; i < 8; i++) {
		player_tile_y_offset[i]=smyoffsets[(spritemap_index<<3)+i];
	}
	
	dub_buffer_counter++;
}

void animatePlayer(){
	if (frame_rate_counter==0){
		//if player attacks, play the attack animation at 60/3 fps, more priority than walking
		if (player_attack){
			player_idle=FALSE;
			frame_rate_divisor=3;
			if (player_direction == 0){
				switch(player_animation_frame){
					case 0:
						setPlayerFrameMap(playattackleft1);
						break;
					case 1:
						setPlayerFrameMap(playattackleft2);
						break;
					case 2:
						setPlayerFrameMap(playattackleft3);
						break;
					case 3:
						setPlayerFrameMap(playattackleft3);
						player_attack = FALSE;
						break;
					default:
						setPlayerFrameMap(playattackleft1);
				}
			} else if (player_direction == 1){
				switch(player_animation_frame){
					case 0:
						setPlayerFrameMap(playattackright1);
						break;
					case 1:
						setPlayerFrameMap(playattackright2);
						break;
					case 2:
						setPlayerFrameMap(playattackright3);
						break;
					case 3:
						setPlayerFrameMap(playattackright3);
						player_attack = FALSE;
						break;
					default:
						setPlayerFrameMap(playattackright1);
				}
			}
		} else {
			// if player moves left, play left walk animation, if player moves right, play right walk animation, more priority over standing
			if (player_move_left) {
				player_idle = FALSE;
				frame_rate_divisor=6;
				switch(player_animation_frame){
					case 0:
						setPlayerFrameMap(playwalkleft1);
						break;
					case 1:
						setPlayerFrameMap(playwalkleft2);
						break;
					case 2:
						setPlayerFrameMap(playwalkleft3);
						break;
					case 3:
						setPlayerFrameMap(playwalkleft4);
						break;
					default:
						setPlayerFrameMap(playwalkleft1);
				}
			} else if (player_move_right) {
				player_idle = FALSE;
				frame_rate_divisor=6;
				switch(player_animation_frame){
					case 0:
						setPlayerFrameMap(playwalkright1);
						break;
					case 1:
						setPlayerFrameMap(playwalkright2);
						break;
					case 2:
						setPlayerFrameMap(playwalkright3);
						break;
					case 3:
						setPlayerFrameMap(playwalkright4);
						break;
					default:
						setPlayerFrameMap(playwalkright1);
				} 
			} else {
				//if player is facing a direction, make it look like they're facing the direction
				if (player_direction == 1 && player_idle == FALSE) {
					setPlayerFrameMap(playidleright);
					player_idle = TRUE;
				} else if (player_direction == 0 && player_idle == FALSE) {
					setPlayerFrameMap(playidleleft);
					player_idle = TRUE;
				}
			}
		}
	}
	//the player will use 4 frames for each animation
	if (player_animation_frame < 4) {
		if (frame_rate_counter > 0) {
			frame_rate_counter--;
		} else {
			frame_rate_counter = frame_rate_divisor;
			player_animation_frame++;
		}
	} else {
		player_animation_frame = 0;
	}
}

void setEnemyFrameMap(unsigned char enemy_frame_map[]) {
	//enemy sprite graphics
	//leave the entire spritesheet in vram, but change sprite tile indexes according to a spritemap
	
	for (uint8_t i = 0; i < 4; i++) {
		set_sprite_tile(i+8, enemy_frame_map[(i<<2)]+32);
	}
	
	
	//offset sprites within the enemy metasprite to save more tiles
	for (uint8_t i = 0; i < 8; i++) {
		enemy_tile_y_offset[i]=enemy_frame_map[(i<<2)+1];
	}
}