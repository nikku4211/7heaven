#ifndef __INPUT_H_INCLUDE
#define __INPUT_H_INCLUDE

#pragma bank 255

#include <gb/gb.h>
#include <stdint.h>

void handleInputGameplay(void);
void handleInputMenu(uint8_t menuOptionsTotal);

#endif