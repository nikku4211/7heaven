#include <gbdk/metasprites.h>

#pragma bank 255

#ifndef __spritemaps_h_INCLUDE
#define __spritemaps_h_INCLUDE

extern const unsigned char smtilesources[];
extern const unsigned char smyoffsets[];

/*
extern const unsigned char playidleleft[];
extern const unsigned char playwalkleft1[];
extern const unsigned char playwalkleft2[];
extern const unsigned char playwalkleft3[];
extern const unsigned char playwalkleft4[];
extern const unsigned char playattackleft1[];
extern const unsigned char playattackleft2[];
extern const unsigned char playattackleft3[];

extern const unsigned char playidleright[];
extern const unsigned char playwalkright1[];
extern const unsigned char playwalkright2[];
extern const unsigned char playwalkright3[];
extern const unsigned char playwalkright4[];
extern const unsigned char playattackright1[];
extern const unsigned char playattackright2[];
extern const unsigned char playattackright3[];

extern const unsigned char zombiewalk1[];
extern const unsigned char zombiewalk2[];
extern const unsigned char zombieburn1[];
extern const unsigned char zombieburn2[];
extern const unsigned char zombieburn3[];
extern const unsigned char zombieburn4[];
*/

extern const metasprite_t zombiewalk1[];
extern const metasprite_t zombiewalk2[];
extern const metasprite_t zombieburn1[];
extern const metasprite_t zombieburn2[];
extern const metasprite_t zombieburn3[];
extern const metasprite_t zombieburn4[];

extern const metasprite_t* const zombiemeta[6];
BANKREF_EXTERN(zombiemeta)

extern const metasprite_t playermetasu[];
extern const metasprite_t playermetasud[];

extern const metasprite_t* const playermeta[2];
BANKREF_EXTERN(playermeta)

#endif
