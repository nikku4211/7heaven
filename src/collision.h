#ifndef __COLLISION_H_INCLUDE
#define __COLLISION_H_INCLUDE

#include <gb/gb.h>
#include <stdint.h>

void playerMapCollision(const unsigned char level_num_col[]);
void enemyMapCollision(const unsigned char level_num_col[]);
void playerEnemyCollision();

#endif