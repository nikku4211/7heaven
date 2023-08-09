#ifndef __ANIMATE_H_INCLUDE
#define __ANIMATE_H_INCLUDE

#include <gb/gb.h>
#include <stdint.h>

void setPlayerFrameMap(uint8_t spritemap_index);
void animatePlayer();
void setEnemyFrameMap(unsigned char enemy_frame_map[]);
void scanline_player_graphics_upload();

#endif