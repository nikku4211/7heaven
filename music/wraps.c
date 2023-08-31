#include <gb/gb.h>
#include <gbdk/platform.h>
#include <gbdk/incbin.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <types.h>

#include "hugedriver.h"

#include "../src/global.h"

//code by Valentina (Coffee Bat)
void hUGE_init_wrapper(const hUGESong_t * song, uint8_t bank) NONBANKED {
  uint8_t b = _current_bank;
  SWITCH_ROM(bank);
  hUGE_init(song);
  music_bank = bank;
  SWITCH_ROM(b);
}

void hUGE_dosound_wrapper(void) NONBANKED {
  uint8_t b = _current_bank;
  SWITCH_ROM(music_bank);
  hUGE_dosound();
  SWITCH_ROM(b);
}