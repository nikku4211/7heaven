#include <gb/gb.h>
#include <gbdk/platform.h>
#include <gbdk/incbin.h>
#include <stdint.h>
#include <stdbool.h>

#include "global.h"

uint8_t joy;
uint8_t joypast;

void handleInputGameplay() {
	//give joy the pad state right now
		joy = joypad();
	
	
    // left or right
    if (joy & J_LEFT) {
			player_direction = 0;
			player_move_left = TRUE;
			player_move_right = FALSE;
    } else if (joy & J_RIGHT) {
			player_direction = 1;
      player_move_right = TRUE;
			player_move_left = FALSE;
    } else {
			player_move_left = FALSE;
			player_move_right = FALSE;
		}
		
		//if player jumps, they can only jump once until they release the button and press it again and are on the ground
		if (joy & J_A && !player_jump && !(joypast & J_A)) {
			player_velocity_Y -= player_jump_velocity;
			player_jump = TRUE;
		}
		
		//if player attacks, they can only attack once until they release the button and press it again
		if (joy & J_B && !player_attack && !(joypast & J_B)) {
			player_attack = TRUE;
			player_animation_frame = 0;
		}
		
		joypast = joy;
}

void handleInputMenu(uint8_t menuOptionsTotal) {
	//give joy the pad state right now
		joy = joypad();
	
	
    // left or right
    if (joy & J_UP && !(joypast & J_UP)) {
			if (menuOption == 0) {
				menuOption = menuOptionsTotal;
			}
			menuOption--;
    } else if (joy & J_DOWN && !(joypast & J_DOWN)) {
			menuOption++;
			if (menuOption == menuOptionsTotal) {
				menuOption = 0;
			}
    }
		
		joypast = joy;
}