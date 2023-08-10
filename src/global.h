#ifndef __GLOBAL_H_INCLUDE
#define __GLOBAL_H_INCLUDEs

extern uint8_t gamemodec;

extern uint8_t menuOption;

extern bool menuConfirm;
extern bool menuBack;

//player position
extern int16_t player_sprite_X,player_sprite_Y;
extern bool player_move_left;
extern bool player_move_right;
extern bool player_idle;
extern bool player_jump;
extern bool player_attack;

extern uint8_t player_direction;

extern int8_t gravity;
extern int8_t player_jump_velocity;
extern int8_t player_terminal_velocity;

extern int8_t player_tile_x_offset[8];
extern int8_t player_tile_y_offset[8];

//player velocity
extern int16_t player_velocity_X,player_velocity_Y;

//player life bar
extern int8_t player_life;
extern uint8_t player_invincible_counter;
extern uint8_t player_invincible_value;

//enemy variables
extern int16_t enemy_sprite_X,enemy_sprite_Y;
extern int8_t enemy_tile_y_offset[8];
extern int8_t enemy_move_divisor;
extern int8_t enemy_move_counter;
extern bool enemy_present;
extern bool enemy_move_left;
extern bool enemy_move_right;
extern bool enemy_idle;
extern bool enemy_jump;

extern int16_t enemy_velocity_X,enemy_velocity_Y;
extern int8_t enemy_jump_velocity;
extern int8_t enemy_terminal_velocity;

extern int8_t enemy_direction;

//sprite animation
extern uint8_t dub_buffer_counter;
extern uint8_t frame_rate_divisor;
extern uint8_t frame_rate_counter;
extern uint8_t player_animation_frame;
extern uint8_t enemy_animation_frame;

extern uint16_t player_tile_locations[8];

extern bool vblank_end;

// current and old positions of the camera in pixels
extern int16_t cameraX, cameraY;

extern int16_t newcameraX, newcameraY;

// current and old position of the map in tiles
extern int16_t map_pos_x, map_pos_y, old_map_pos_x, old_map_pos_y;

//level variables
extern uint8_t level_num;

typedef struct level_t {
    const unsigned char * tile_maps;
    const unsigned char * collision_maps;
		const uint8_t map_width;
		const uint8_t map_height;
} level_t; 

extern const level_t game_levels[];

extern const level_t * current_level;

extern int16_t entity_screen;

INCBIN_EXTERN(player_tiles)
INCBIN_EXTERN(zombie_tiles)
#endif