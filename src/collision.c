#include <gb/gb.h>
#include <gbdk/platform.h>
#include <gbdk/incbin.h>
#include <stdint.h>
#include <stdbool.h>

//collision tile definitions
#define solidtile 1
#define semisolidtile 2

#define player_col_left 4
#define player_col_right 11
#define player_col_top 0
#define player_col_bottom 15

#define player_attack_box_left 0
#define player_attack_box_right 15
#define player_attack_box_top 0
#define player_attack_box_bottom 31

#define enemy_col_left -7
#define enemy_col_right 7
#define enemy_col_top -15
#define enemy_col_bottom 15

#include "global.h"

	//define entity collision box
	static uint16_t entity_left_col_coord;
	static uint16_t entity_right_col_coord;
	static uint16_t entity_top_col_coord;
	static uint16_t entity_bottom_col_coord;
	
	//define entity collision box in 8x8 tiles
	static uint16_t x_tile_coord_left_col_entity;
	static uint16_t x_tile_coord_right_col_entity;
	static uint16_t y_tile_coord_top_col_entity;
	static uint16_t y_tile_coord_bottom_col_entity;
	
	//define array indexes for entity collision
	static uint16_t array_index_top_left_col_box;
	static uint16_t array_index_top_right_col_box;
	static uint16_t array_index_bottom_left_col_box;
	static uint16_t array_index_bottom_right_col_box;
	
	//what's the type of collision detected?
	static uint8_t tile_col_type_top_left;
	static uint8_t tile_col_type_top_right;
	static uint8_t tile_col_type_bottom_left;
	static uint8_t tile_col_type_bottom_right;
	
	static int16_t blocked_coord;
	
	static int16_t entity_sprite_previous_Y;
	
	void getHurt();
	
void playerMapCollision(const unsigned char level_num_col[]){
	entity_sprite_previous_Y = player_sprite_Y;
	
	entity_screen = (player_sprite_X & 0xFF00) << 2;
	
	//move player
	
	if(player_move_left){
		player_sprite_X -= player_velocity_X;
		
		//check player hitbox in 8x8 grid for top
		entity_top_col_coord = player_sprite_Y + player_col_top;
		y_tile_coord_top_col_entity = entity_top_col_coord >> 3;
		
		//check player hitbox in 8x8 grid for bottom
		entity_bottom_col_coord = player_sprite_Y + player_col_bottom;
		y_tile_coord_bottom_col_entity = entity_bottom_col_coord >> 3;
		
		//check player hitbox in 8x8 grid for left
		entity_left_col_coord = player_sprite_X + player_col_left;
		x_tile_coord_left_col_entity = entity_left_col_coord >> 3;
		
		array_index_top_left_col_box = (x_tile_coord_left_col_entity+entity_screen) + (y_tile_coord_top_col_entity << 5);
		tile_col_type_top_left = level_num_col[array_index_top_left_col_box];
		
		array_index_bottom_left_col_box = (x_tile_coord_left_col_entity+entity_screen) + (y_tile_coord_bottom_col_entity << 5);
		tile_col_type_bottom_left = level_num_col[array_index_bottom_left_col_box];
		
		//if tile to the top or bottom left is solid, don't move
		if((tile_col_type_top_left == solidtile) || (tile_col_type_bottom_left == solidtile)){
			blocked_coord = (x_tile_coord_left_col_entity << 3) + 8 - player_col_left;
			player_sprite_X = blocked_coord;
		}
	}else if(player_move_right){
		player_sprite_X += player_velocity_X;
		
		//check player hitbox in 8x8 grid for top
		entity_top_col_coord = player_sprite_Y + player_col_top;
		y_tile_coord_top_col_entity = entity_top_col_coord >> 3;
		
		//check player hitbox in 8x8 grid for bottom
		entity_bottom_col_coord = player_sprite_Y + player_col_bottom;
		y_tile_coord_bottom_col_entity = entity_bottom_col_coord >> 3;
		
		//check player hitbox in 8x8 grid for right
		entity_right_col_coord = player_sprite_X + player_col_right;
		x_tile_coord_right_col_entity = entity_right_col_coord >> 3;
		
		array_index_top_right_col_box = (x_tile_coord_right_col_entity+entity_screen) + (y_tile_coord_top_col_entity << 5);
		tile_col_type_top_right = level_num_col[array_index_top_right_col_box];
		
		array_index_bottom_right_col_box = (x_tile_coord_right_col_entity+entity_screen) + (y_tile_coord_bottom_col_entity << 5);
		tile_col_type_bottom_right = level_num_col[array_index_bottom_right_col_box];
		
		//if tile to the top or bottom right is solid, don't move
		if(tile_col_type_top_right == solidtile || tile_col_type_bottom_right == solidtile){
			blocked_coord = (x_tile_coord_right_col_entity << 3) - 1 - player_col_right;
			player_sprite_X = blocked_coord;
		}
	}
	
		player_velocity_Y += gravity;
		if(player_velocity_Y > player_terminal_velocity) player_velocity_Y=player_terminal_velocity;
		player_sprite_Y += player_velocity_Y;
		
		//check player hitbox in 8x8 grid for top
		entity_top_col_coord = player_sprite_Y + player_col_top;
		y_tile_coord_top_col_entity = entity_top_col_coord >> 3;
		
		//check player hitbox in 8x8 grid for bottom
		entity_bottom_col_coord = player_sprite_Y + player_col_bottom;
		y_tile_coord_bottom_col_entity = entity_bottom_col_coord >> 3;
		
		//check player bottom left
		entity_left_col_coord = player_sprite_X + player_col_left;
		x_tile_coord_left_col_entity = entity_left_col_coord >> 3;
		
		//check player bottom right
		entity_right_col_coord = player_sprite_X + player_col_right;
		x_tile_coord_right_col_entity = entity_right_col_coord >> 3;
		
		array_index_top_left_col_box = (x_tile_coord_left_col_entity+entity_screen) + (y_tile_coord_top_col_entity << 5);
		tile_col_type_top_left = level_num_col[array_index_top_left_col_box];
		
		array_index_top_right_col_box = (x_tile_coord_right_col_entity+entity_screen) + (y_tile_coord_top_col_entity << 5);
		tile_col_type_top_right = level_num_col[array_index_top_right_col_box];
		
		array_index_bottom_left_col_box = (x_tile_coord_left_col_entity+entity_screen) + (y_tile_coord_bottom_col_entity << 5);
		tile_col_type_bottom_left = level_num_col[array_index_bottom_left_col_box];
		
		array_index_bottom_right_col_box = (x_tile_coord_right_col_entity+entity_screen) + (y_tile_coord_bottom_col_entity << 5);
		tile_col_type_bottom_right = level_num_col[array_index_bottom_right_col_box];
		
		//if tile to the bottom left or bottom right is solid, don't move
		if(tile_col_type_bottom_left == solidtile || tile_col_type_bottom_right == solidtile){
			blocked_coord = (y_tile_coord_bottom_col_entity << 3) - 1 - player_col_bottom;
			player_sprite_Y = blocked_coord;
			player_velocity_Y = 0;
			if (player_jump) {
			player_jump = FALSE;
			}
		}else if(tile_col_type_top_left == solidtile || tile_col_type_top_right == solidtile){ //don't go through solid blocks from the bottom
			blocked_coord = (y_tile_coord_top_col_entity << 3) + 8 - player_col_top;
			player_sprite_Y = blocked_coord;
			player_velocity_Y = 0;
		}else if((tile_col_type_bottom_left == semisolidtile || tile_col_type_bottom_right == semisolidtile) && player_sprite_Y > entity_sprite_previous_Y){ //must be touching the very top of a semisolid to stand on it
			blocked_coord = (y_tile_coord_bottom_col_entity << 3) - 1 - player_col_bottom;
			uint8_t platform_below_pushup = 8;
			if(player_sprite_Y < (blocked_coord + platform_below_pushup) || entity_sprite_previous_Y < blocked_coord){
			player_sprite_Y = blocked_coord;
			player_velocity_Y = 0;
			if (player_jump) {
			player_jump = FALSE;
			}
			}
		}
}

void enemyMapCollision(const unsigned char level_num_col[]){
	entity_sprite_previous_Y = enemy_sprite_Y;
	
	entity_screen = (enemy_sprite_X & 0xFF00) << 2;
	
	if(enemy_move_left){
		enemy_sprite_X -= enemy_velocity_X;
		
		//check enemy hitbox in 8x8 grid for top
		entity_top_col_coord = enemy_sprite_Y + enemy_col_top;
		y_tile_coord_top_col_entity = entity_top_col_coord >> 3;
		
		//check enemy hitbox in 8x8 grid for bottom
		entity_bottom_col_coord = enemy_sprite_Y + enemy_col_bottom;
		y_tile_coord_bottom_col_entity = entity_bottom_col_coord >> 3;
		
		//check enemy hitbox in 8x8 grid for left
		entity_left_col_coord = enemy_sprite_X + enemy_col_left;
		x_tile_coord_left_col_entity = entity_left_col_coord >> 3;
		
		array_index_top_left_col_box = (x_tile_coord_left_col_entity+entity_screen) + (y_tile_coord_top_col_entity << 5);
		tile_col_type_top_left = level_num_col[array_index_top_left_col_box];
		
		array_index_bottom_left_col_box = (x_tile_coord_left_col_entity+entity_screen) + (y_tile_coord_bottom_col_entity << 5);
		tile_col_type_bottom_left = level_num_col[array_index_bottom_left_col_box];
		
		//if tile to the top or bottom left is solid, don't move
		if((tile_col_type_top_left == solidtile) || (tile_col_type_bottom_left == solidtile)){
			blocked_coord = (x_tile_coord_left_col_entity << 3) + 8 - enemy_col_left;
			enemy_sprite_X = blocked_coord;
		}
	}else if(enemy_move_right){
		enemy_sprite_X += enemy_velocity_X;
		
		//check enemy hitbox in 8x8 grid for top
		entity_top_col_coord = enemy_sprite_Y + enemy_col_top;
		y_tile_coord_top_col_entity = entity_top_col_coord >> 3;
		
		//check enemy hitbox in 8x8 grid for bottom
		entity_bottom_col_coord = enemy_sprite_Y + enemy_col_bottom;
		y_tile_coord_bottom_col_entity = entity_bottom_col_coord >> 3;
		
		//check enemy hitbox in 8x8 grid for right
		entity_right_col_coord = enemy_sprite_X + enemy_col_right;
		x_tile_coord_right_col_entity = entity_right_col_coord >> 3;
		
		array_index_top_right_col_box = (x_tile_coord_right_col_entity+entity_screen) + (y_tile_coord_top_col_entity << 5);
		tile_col_type_top_right = level_num_col[array_index_top_right_col_box];
		
		array_index_bottom_right_col_box = (x_tile_coord_right_col_entity+entity_screen) + (y_tile_coord_bottom_col_entity << 5);
		tile_col_type_bottom_right = level_num_col[array_index_bottom_right_col_box];
		
		//if tile to the top or bottom right is solid, don't move
		if(tile_col_type_top_right == solidtile || tile_col_type_bottom_right == solidtile){
			blocked_coord = (x_tile_coord_right_col_entity << 3) - 1 - enemy_col_right;
			enemy_sprite_X = blocked_coord;
		}
	}
	
		enemy_velocity_Y += gravity;
		if(enemy_velocity_Y > enemy_terminal_velocity) enemy_velocity_Y=enemy_terminal_velocity;
		enemy_sprite_Y += enemy_velocity_Y;
		
		//check enemy hitbox in 8x8 grid for top
		entity_top_col_coord = enemy_sprite_Y + enemy_col_top;
		y_tile_coord_top_col_entity = entity_top_col_coord >> 3;
		
		//check enemy hitbox in 8x8 grid for bottom
		entity_bottom_col_coord = enemy_sprite_Y + enemy_col_bottom;
		y_tile_coord_bottom_col_entity = entity_bottom_col_coord >> 3;
		
		//check enemy bottom left
		entity_left_col_coord = enemy_sprite_X + enemy_col_left;
		x_tile_coord_left_col_entity = entity_left_col_coord >> 3;
		
		//check enemy bottom right
		entity_right_col_coord = enemy_sprite_X + enemy_col_right;
		x_tile_coord_right_col_entity = entity_right_col_coord >> 3;
		
		array_index_top_left_col_box = (x_tile_coord_left_col_entity+entity_screen) + (y_tile_coord_top_col_entity << 5);
		tile_col_type_top_left = level_num_col[array_index_top_left_col_box];
		
		array_index_top_right_col_box = (x_tile_coord_right_col_entity+entity_screen) + (y_tile_coord_top_col_entity << 5);
		tile_col_type_top_right = level_num_col[array_index_top_right_col_box];
		
		array_index_bottom_left_col_box = (x_tile_coord_left_col_entity+entity_screen) + (y_tile_coord_bottom_col_entity << 5);
		tile_col_type_bottom_left = level_num_col[array_index_bottom_left_col_box];
		
		array_index_bottom_right_col_box = (x_tile_coord_right_col_entity+entity_screen) + (y_tile_coord_bottom_col_entity << 5);
		tile_col_type_bottom_right = level_num_col[array_index_bottom_right_col_box];
		
		//if tile to the bottom left or bottom right is solid, don't move
		if(tile_col_type_bottom_left == solidtile || tile_col_type_bottom_right == solidtile){
			blocked_coord = (y_tile_coord_bottom_col_entity << 3) - 1 - enemy_col_bottom;
			enemy_sprite_Y = blocked_coord;
			enemy_velocity_Y = 0;
			if (enemy_jump) {
			enemy_jump = FALSE;
			}
		}else if(tile_col_type_top_left == solidtile || tile_col_type_top_right == solidtile){ //don't go through solid blocks from the bottom
			blocked_coord = (y_tile_coord_top_col_entity << 3) + 8 - enemy_col_top;
			enemy_sprite_Y = blocked_coord;
			enemy_velocity_Y = 0;
		}else if((tile_col_type_bottom_left == semisolidtile || tile_col_type_bottom_right == semisolidtile) && enemy_sprite_Y > entity_sprite_previous_Y){ //must be touching the very top of a semisolid to stand on it
			blocked_coord = (y_tile_coord_bottom_col_entity << 3) - 1 - enemy_col_bottom;
			uint8_t platform_below_pushup = 8;
			if(enemy_sprite_Y < (blocked_coord + platform_below_pushup) || entity_sprite_previous_Y < blocked_coord){
			enemy_sprite_Y = blocked_coord;
			enemy_velocity_Y = 0;
			if (enemy_jump) {
			enemy_jump = FALSE;
			}
			}
		}
	
}

void playerEnemyCollision() {
	int16_t player_left_col_coord;
	int16_t player_right_col_coord;
	int16_t player_top_col_coord;
	int16_t player_bottom_col_coord;
	
	int16_t player_attack_left_col_coord;
	int16_t player_attack_right_col_coord;
	int16_t player_attack_top_col_coord;
	int16_t player_attack_bottom_col_coord;
	
	int16_t enemy_left_col_coord;
	int16_t enemy_right_col_coord;
	int16_t enemy_top_col_coord;
	int16_t enemy_bottom_col_coord;
	
	player_top_col_coord = player_sprite_Y + player_col_top;
	player_bottom_col_coord = player_sprite_Y + player_col_bottom;
	player_left_col_coord = player_sprite_X + player_col_left;
	player_right_col_coord = player_sprite_X + player_col_right;
	
	player_attack_top_col_coord = player_sprite_Y + player_attack_box_top;
	player_attack_bottom_col_coord = player_sprite_Y + player_attack_box_bottom;
	player_attack_left_col_coord = player_sprite_X + player_attack_box_left;
	player_attack_right_col_coord = player_sprite_X + player_attack_box_right;
	
	enemy_top_col_coord = enemy_sprite_Y + enemy_col_top;
	enemy_bottom_col_coord = enemy_sprite_Y + enemy_col_bottom;
	enemy_left_col_coord = enemy_sprite_X + enemy_col_left;
	enemy_right_col_coord = enemy_sprite_X + enemy_col_right;
	
	//apply AABB collision on player and enemy
	if (player_right_col_coord > enemy_left_col_coord &&
			player_left_col_coord < enemy_right_col_coord && 
			player_bottom_col_coord > enemy_top_col_coord && 
			player_top_col_coord < enemy_bottom_col_coord && 
			player_invincible_counter == 0){
		getHurt();
	}
	
	if (player_attack &&
			player_direction == 0 &&
			player_attack_right_col_coord - 16 > enemy_left_col_coord &&
			player_attack_left_col_coord - 16< enemy_right_col_coord && 
			player_attack_bottom_col_coord > enemy_top_col_coord && 
			player_attack_top_col_coord < enemy_bottom_col_coord){
		enemy_present = FALSE;
		enemy_sprite_Y = 224;
	} else if (player_attack &&
			player_direction == 1 &&
			player_attack_right_col_coord + 16 > enemy_left_col_coord &&
			player_attack_left_col_coord + 16< enemy_right_col_coord && 
			player_attack_bottom_col_coord > enemy_top_col_coord && 
			player_attack_top_col_coord < enemy_bottom_col_coord) {
		enemy_present = FALSE;
		enemy_sprite_Y = 224;
	}
}