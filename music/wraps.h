#include <gb/gb.h>
#include <gbdk/platform.h>
#include <gbdk/incbin.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <types.h>

#include "../src/global.h"

#include "hugedriver.h"

#ifndef __WRAPS_H_INCLUDE
#define __WRAPS_H_INCLUDE

void hUGE_init_wrapper(const hUGESong_t * song, uint8_t bank) NONBANKED;

void hUGE_dosound_wrapper(void) NONBANKED;
	
#endif