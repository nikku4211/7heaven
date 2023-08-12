#include <stdint.h>
#include <stdio.h>
#include <gbdk/platform.h>
#include <gbdk/incbin.h>

#pragma bank 255

BANKREF(player_tiles)

//player sprite tiles
INCBIN(player_tiles, "res/7heavenplayerspritesheettspr.2bpp")

BANKREF(zombie_tiles)

//zombie sprite tiles
INCBIN(zombie_tiles, "res/zombieenemyspritesheettspr.2bpp")