#include <gb/gb.h>
#include <gbdk/incbin.h>
#include <gbdk/metasprites.h>
#include <stdint.h>
#include <stdbool.h>

#include "global.h"

uint8_t gamemodec = 1;

uint8_t menuOption;

//player position
int16_t player_sprite_X,player_sprite_Y;
bool player_move_left = FALSE;
bool player_move_right = FALSE;
bool player_idle = FALSE;
bool player_jump = FALSE;
bool player_attack = FALSE;

uint8_t player_direction = 1;

int8_t gravity;
int8_t player_jump_velocity = 8;
int8_t player_terminal_velocity = 7;

int8_t player_tile_x_offset[8];
int8_t player_tile_y_offset[8];

//player velocity
int16_t player_velocity_X,player_velocity_Y;

//player life bar
int8_t player_life = 8;
uint8_t player_invincible_counter = 0;
uint8_t player_invincible_value = 60;

//enemy variables
int16_t enemy_sprite_X,enemy_sprite_Y;
int8_t enemy_tile_y_offset[8];
int8_t enemy_move_divisor;
int8_t enemy_move_counter;
bool enemy_present;
bool enemy_move_left = FALSE;
bool enemy_move_right = FALSE;
bool enemy_idle = FALSE;
bool enemy_jump = FALSE;

int16_t enemy_velocity_X,enemy_velocity_Y;
int8_t enemy_jump_velocity = 8;
int8_t enemy_terminal_velocity = 7;

int8_t enemy_direction;

//zombie enemy variables

//sprite animation
uint8_t dub_buffer_counter;
uint8_t frame_rate_divisor;
uint8_t frame_rate_counter;
uint8_t player_animation_frame;
uint8_t enemy_animation_frame;

uint16_t player_tile_locations[8] = {0,0,0,0,0,0,0,0};

// current and old positions of the camera in pixels
int16_t cameraX, cameraY;

int16_t newcameraX, newcameraY;

// current and old position of the map in tiles
int16_t map_pos_x, map_pos_y, old_map_pos_x, old_map_pos_y;

//level variables
uint8_t level_num = 0;

//background test tilemap
#include "../level/str3ttestmap_tile.h"
#include "../level/str3ttestmap2_tile.h"

//level collision map
#include "../level/str3ttestmap_collision.h"
#include "../level/str3ttestmap2_collision.h"

const level_t game_levels[] = {
    {.tile_maps = str3ttestmap_tile, .collision_maps = str3ttestmap_collision, .map_width = 32, .map_height = 18}, 
		{.tile_maps = str3ttestmap2_tile, .collision_maps = str3ttestmap2_collision, .map_width = 64, .map_height = 18}, 
};

const level_t * current_level;

//player sprite tiles
INCBIN(player_tiles, "res/7heavenplayerspritesheettspr.2bpp")

//zombie sprite tiles
INCBIN(zombie_tiles, "res/zombieenemyspritesheettspr.2bpp")