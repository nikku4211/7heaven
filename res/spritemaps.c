#include <gb/gb.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>
#include <stdint.h>

#pragma bank 255

/*
player spritemap format:
tile source in 8x16, x-offset, y-offset, unused

*/

//player
//left

const unsigned char smtilesources[] = {
	 1,  2,  3,  4, 16, 17, 18, 19,
	 1,  2,  3,  4, 12, 13, 14, 15,
	 1,  2,  3,  4, 28, 29, 30, 31,
	 1,  2,  3,  4, 28, 40, 41, 42,
	 1,  2,  3,  4, 28, 43, 44, 45,
	 0,  5,  6,  7, 20, 21, 22, 23,
	 0,  8,  6,  9, 24, 25, 26, 27,
	 0,  8,  6,  9, 24, 25, 10, 11,
	32, 33, 34,  0, 48, 49, 50, 51,
	32, 33, 34,  0, 64, 65, 66, 67,
	32, 33, 34,  0, 68, 69, 70, 71,
	32, 33, 34,  0, 72, 73, 74, 71,
	32, 33, 34,  0, 75, 76, 77, 71,
	35, 36, 37, 38, 52, 53, 54, 55,
	39, 36, 61, 62, 56, 57, 58, 59,
	46, 36, 47,  0, 60, 57, 58, 59
};
const unsigned char smyoffsets[] = {
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	2, 2, 2, 2, 2, 2, 2, 2,
	1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	2, 2, 2, 2, 2, 2, 2, 2,
	1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1
};
/*
const unsigned char playidleleft[] = {
	 1, 0, 1,0,   2, 0, 1,0,   3, 0, 1,0,   4, 0, 1,0,
	16, 0, 1,0,  17, 0, 1,0,  18, 0, 1,0,  19, 0, 1,0
};

const unsigned char playwalkleft1[] = {
	 1, 0, 1,0,   2, 0, 1,0,   3, 0, 1,0,   4, 0, 1,0,
	12, 0, 1,0,  13, 0, 1,0,  14, 0, 1,0,  15, 0, 1,0
};

const unsigned char playwalkleft2[] = {
	 1, 0, 2,0,   2, 0, 2,0,   3, 0, 2,0,   4, 0, 2,0,
	28, 0, 2,0,  29, 0, 2,0,  30, 0, 2,0,  31, 0, 2,0
};

const unsigned char playwalkleft3[] = {
	 1, 0, 1,0,   2, 0, 1,0,   3, 0, 1,0,   4, 0, 1,0,
	28, 0, 1,0,  40, 0, 1,0,  41, 0, 1,0,  42, 0, 1,0
};

const unsigned char playwalkleft4[] = {
	 1, 0, 0,0,   2, 0, 0,0,   3, 0, 0,0,   4, 0, 0,0,
	28, 0, 0,0,  43, 0, 0,0,  44, 0, 0,0,  45, 0, 0,0
};

const unsigned char playattackleft1[] = {
	 0, 0, 1,0,   5, 0, 1,0,   6, 0, 1,0,   7, 0, 1,0,
	20, 0, 1,0,  21, 0, 1,0,  22, 0, 1,0,  23, 0, 1,0
};

const unsigned char playattackleft2[] = {
	 0, 0, 1,0,   8, 0, 1,0,   6, 0, 1,0,   9, 0, 1,0,
	24, 0, 1,0,  25, 0, 1,0,  26, 0, 1,0,  27, 0, 1,0
};

const unsigned char playattackleft3[] = {
	 0, 0, 1,0,   8, 0, 1,0,   6, 0, 1,0,   9, 0, 1,0,
	24, 0, 1,0,  25, 0, 1,0,  10, 0, 1,0,  11, 0, 1,0
};

//right
const unsigned char playidleright[] = {
	32, 0, 1,0,  33, 0, 1,0,  34, 0, 1,0,   0, 0, 1,0,
	48, 0, 1,0,  49, 0, 1,0,  50, 0, 1,0,  51, 0, 1,0
};

const unsigned char playwalkright1[] = {
	32, 0, 1,0,  33, 0, 1,0,  34, 0, 1,0,  0, 0, 1,0,
	64, 0, 1,0,  65, 0, 1,0,  66, 0, 1,0,  67, 0, 1,0
};

const unsigned char playwalkright2[] = {
	32, 0, 2,0,  33, 0, 2,0,  34, 0, 2,0,   0, 0, 2,0,
	68, 0, 2,0,  69, 0, 2,0,  70, 0, 2,0,  71, 0, 2,0
};

const unsigned char playwalkright3[] = {
	32, 0, 1,0,  33, 0, 1,0,  34, 0, 1,0,   0, 0, 1,0,
	72, 0, 1,0,  73, 0, 1,0,  74, 0, 1,0,  71, 0, 1,0
};

const unsigned char playwalkright4[] = {
	32, 0, 0,0,  33, 0, 0,0,  34, 0, 0,0,   0, 0, 0,0,
	75, 0, 0,0,  76, 0, 0,0,  77, 0, 0,0,  71, 0, 0,0
};

const unsigned char playattackright1[] = {
	35, 0, 1,0,  36, 0, 1,0,  37, 0, 1,0,  38, 0, 1,0,
	52, 0, 1,0,  53, 0, 1,0,  54, 0, 1,0,  55, 0, 1,0
};

const unsigned char playattackright2[] = {
	39, 0, 1,0,  36, 0, 1,0,  61, 0, 1,0,  62, 0, 1,0,
	56, 0, 1,0,  57, 0, 1,0,  58, 0, 1,0,  59, 0, 1,0
};

const unsigned char playattackright3[] = {
	46, 0, 1,0,  36, 0, 1,0,  47, 0, 1,0,   0, 0, 1,0,
	60, 0, 1,0,  57, 0, 1,0,  58, 0, 1,0,  59, 0, 1,0
};
*/
/*
enemy spritemap format:
tile source in 8x16, y-offset, x-flip, y-flip

*/
//zombie
//walk

/*
const unsigned char zombiewalk1[] = {
	 0, 0, 0, 0,   2, 0, 0, 0,
	22, 0, 0, 0,  24, 0, 0, 0
};

const unsigned char zombiewalk2[] = {
	 0, 1, 0, 0,   2, 1, 0, 0,
	26, 0, 0, 0,  4, 0, 0, 0
};

//burn
const unsigned char zombieburn1[] = {
	 6, 0, 0, 0,   8, 0, 0, 0,
	28, 0, 0, 0,  30, 0, 0, 0
};

const unsigned char zombieburn2[] = {
	10, 0, 0, 0,  12, 0, 0, 0,
	32, 0, 0, 0,  34, 0, 0, 0
};

const unsigned char zombieburn3[] = {
	14, 0, 0, 0,  16, 0, 0, 0,
	36, 0, 0, 0,  38, 0, 0, 0
};

const unsigned char zombieburn4[] = {
	18, 0, 0, 0,  20, 0, 0, 0,
	40, 0, 0, 0,  42, 0, 0, 0
};
*/

BANKREF(zombiemeta)

const metasprite_t zombiewalk1[] = {
	METASPR_ITEM( 0,  0,  0, 0), METASPR_ITEM(0, 8,  2, 0),
	METASPR_ITEM(16, -8, 22, 0), METASPR_ITEM(0, 8, 24, 0), METASPR_TERM
};

const metasprite_t zombiewalk2[] = {
	METASPR_ITEM( 1,  0,  0, 0), METASPR_ITEM(0, 8, 2, 0),
	METASPR_ITEM(16, -8, 26, 0), METASPR_ITEM(0, 8, 4, 0), METASPR_TERM
};

const metasprite_t zombieburn1[] = {
	METASPR_ITEM( 0,  0,  6, 0), METASPR_ITEM(0, 8,  8, 0),
	METASPR_ITEM(16, -8, 28, 0), METASPR_ITEM(0, 8, 30, 0), METASPR_TERM
};

const metasprite_t zombieburn2[] = {
	METASPR_ITEM( 0,  0, 10, 0), METASPR_ITEM(0, 8, 12, 0),
	METASPR_ITEM(16, -8, 32, 0), METASPR_ITEM(0, 8, 34, 0), METASPR_TERM
};

const metasprite_t zombieburn3[] = {
	METASPR_ITEM( 0,  0, 14, 0), METASPR_ITEM(0, 8, 16, 0),
	METASPR_ITEM(16, -8, 36, 0), METASPR_ITEM(0, 8, 38, 0), METASPR_TERM
};

const metasprite_t zombieburn4[] = {
	METASPR_ITEM( 0,  0, 18, 0), METASPR_ITEM(0, 8, 20, 0),
	METASPR_ITEM(16, -8, 40, 0), METASPR_ITEM(0, 8, 42, 0), METASPR_TERM
};

const metasprite_t* const zombiemeta[6] = {
	zombiewalk1, zombiewalk2, zombieburn1, zombieburn2, zombieburn3, zombieburn4
};

BANKREF(playermeta)

const metasprite_t playermetasu[] = {
	METASPR_ITEM( 0,   0, 0, 0), METASPR_ITEM( 0, 8,  2, 0), METASPR_ITEM( 0, 8,  4, 0), METASPR_ITEM( 0, 8,  6, 0), 
	METASPR_ITEM(16, -24, 8, 0), METASPR_ITEM( 0, 8, 10, 0), METASPR_ITEM( 0, 8, 12, 0), METASPR_ITEM( 0, 8, 14, 0), METASPR_TERM
};

const metasprite_t playermetasud[] = {
	METASPR_ITEM( 0,   0, 16, 0), METASPR_ITEM( 0, 8, 18, 0), METASPR_ITEM( 0, 8, 20, 0), METASPR_ITEM( 0, 8, 22, 0), 
	METASPR_ITEM(16, -24, 24, 0), METASPR_ITEM( 0, 8, 26, 0), METASPR_ITEM( 0, 8, 28, 0), METASPR_ITEM( 0, 8, 30, 0), METASPR_TERM
};

const metasprite_t* const playermeta[2] = {
	playermetasu, playermetasud
};
