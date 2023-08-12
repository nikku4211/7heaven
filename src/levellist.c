#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <types.h>

#include "global.h"

//background test tilemap
#include "../level/str3ttestmap_tile.h"
#include "../level/str3ttestmap2_tile.h"
#include "../level/str3ttestmap3_tile.h"

//level collision map
#include "../level/str3ttestmap_collision.h"
#include "../level/str3ttestmap2_collision.h"
#include "../level/str3ttestmap3_collision.h"

const level_t game_levels[] = {
    {.tile_maps = str3ttestmap_tile, .collision_maps = str3ttestmap_collision, .map_width = 32, .map_height = 32}, 
		{.tile_maps = str3ttestmap2_tile, .collision_maps = str3ttestmap2_collision, .map_width = 64, .map_height = 32}, 
		{.tile_maps = str3ttestmap3_tile, .collision_maps = str3ttestmap3_collision, .map_width = 160, .map_height = 32},
};

const level_t * current_level;