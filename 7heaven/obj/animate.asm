;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.2.2 #13350 (MINGW64)
;--------------------------------------------------------
	.module animate
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _vmemcpy
	.globl _scanline_player_graphics_upload
	.globl _setPlayerFrameMap
	.globl _animatePlayer
	.globl _setEnemyFrameMap
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
	G$scanline_player_graphics_upload$0$0	= .
	.globl	G$scanline_player_graphics_upload$0$0
	C$animate.c$34$0_0$133	= .
	.globl	C$animate.c$34$0_0$133
;src/animate.c:34: void scanline_player_graphics_upload() {
;	---------------------------------
; Function scanline_player_graphics_upload
; ---------------------------------
_scanline_player_graphics_upload::
	C$animate.c$35$1_0$133	= .
	.globl	C$animate.c$35$1_0$133
;src/animate.c:35: vmemcpy(_VRAM8000+0+((dub_buffer_counter & 1)<<8), player_tiles+player_tile_locations[0], 32);
	ld	hl, #_player_tile_locations
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #_player_tiles
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	a, (#_dub_buffer_counter)
	and	a, #0x01
	ld	d, a
	ld	e, #0x00
	ld	hl, #__VRAM8000
	add	hl, de
	ld	de, #0x0020
	push	de
	push	bc
	push	hl
	call	_vmemcpy
	add	sp, #6
	C$animate.c$36$1_0$133	= .
	.globl	C$animate.c$36$1_0$133
;src/animate.c:36: vmemcpy(_VRAM8000+32+((dub_buffer_counter & 1)<<8), player_tiles+player_tile_locations[1], 32);
	ld	hl, #_player_tile_locations + 2
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #_player_tiles
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	a, (#_dub_buffer_counter)
	and	a, #0x01
	ld	d, a
	ld	e, #0x00
	ld	hl, #(__VRAM8000 + 32)
	add	hl, de
	ld	de, #0x0020
	push	de
	push	bc
	push	hl
	call	_vmemcpy
	add	sp, #6
	C$animate.c$37$1_0$133	= .
	.globl	C$animate.c$37$1_0$133
;src/animate.c:37: vmemcpy(_VRAM8000+64+((dub_buffer_counter & 1)<<8), player_tiles+player_tile_locations[2], 32);
	ld	hl, #_player_tile_locations + 4
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #_player_tiles
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	de, #__VRAM8000 + 64
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (#_dub_buffer_counter)
	and	a, #0x01
;	spillPairReg hl
;	spillPairReg hl
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	l, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, de
	ld	de, #0x0020
	push	de
	push	bc
	push	hl
	call	_vmemcpy
	add	sp, #6
	C$animate.c$38$1_0$133	= .
	.globl	C$animate.c$38$1_0$133
;src/animate.c:38: vmemcpy(_VRAM8000+96+((dub_buffer_counter & 1)<<8), player_tiles+player_tile_locations[3], 32);
	ld	hl, #_player_tile_locations + 6
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #_player_tiles
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	de, #__VRAM8000 + 96
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (#_dub_buffer_counter)
	and	a, #0x01
;	spillPairReg hl
;	spillPairReg hl
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	l, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, de
	ld	de, #0x0020
	push	de
	push	bc
	push	hl
	call	_vmemcpy
	add	sp, #6
	C$animate.c$39$1_0$133	= .
	.globl	C$animate.c$39$1_0$133
;src/animate.c:39: vmemcpy(_VRAM8000+128+((dub_buffer_counter & 1)<<8), player_tiles+player_tile_locations[4], 32);
	ld	hl, #_player_tile_locations + 8
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #_player_tiles
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	de, #__VRAM8000 + 128
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (#_dub_buffer_counter)
	and	a, #0x01
;	spillPairReg hl
;	spillPairReg hl
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	l, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, de
	ld	de, #0x0020
	push	de
	push	bc
	push	hl
	call	_vmemcpy
	add	sp, #6
	C$animate.c$40$1_0$133	= .
	.globl	C$animate.c$40$1_0$133
;src/animate.c:40: vmemcpy(_VRAM8000+160+((dub_buffer_counter & 1)<<8), player_tiles+player_tile_locations[5], 32);
	ld	hl, #_player_tile_locations + 10
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #_player_tiles
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	de, #__VRAM8000 + 160
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (#_dub_buffer_counter)
	and	a, #0x01
;	spillPairReg hl
;	spillPairReg hl
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	l, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, de
	ld	de, #0x0020
	push	de
	push	bc
	push	hl
	call	_vmemcpy
	add	sp, #6
	C$animate.c$41$1_0$133	= .
	.globl	C$animate.c$41$1_0$133
;src/animate.c:41: vmemcpy(_VRAM8000+192+((dub_buffer_counter & 1)<<8), player_tiles+player_tile_locations[6], 32);
	ld	hl, #_player_tile_locations + 12
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #_player_tiles
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	de, #__VRAM8000 + 192
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (#_dub_buffer_counter)
	and	a, #0x01
;	spillPairReg hl
;	spillPairReg hl
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	l, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, de
	ld	de, #0x0020
	push	de
	push	bc
	push	hl
	call	_vmemcpy
	add	sp, #6
	C$animate.c$42$1_0$133	= .
	.globl	C$animate.c$42$1_0$133
;src/animate.c:42: vmemcpy(_VRAM8000+224+((dub_buffer_counter & 1)<<8), player_tiles+player_tile_locations[7], 32);
	ld	hl, #_player_tile_locations + 14
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	hl, #_player_tiles
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	de, #__VRAM8000 + 224
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
	ld	a, (#_dub_buffer_counter)
	and	a, #0x01
;	spillPairReg hl
;	spillPairReg hl
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	l, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, de
	ld	de, #0x0020
	push	de
	push	bc
	push	hl
	call	_vmemcpy
	add	sp, #6
	C$animate.c$55$1_0$133	= .
	.globl	C$animate.c$55$1_0$133
;src/animate.c:55: dub_buffer_counter++;
	ld	hl, #_dub_buffer_counter
	inc	(hl)
	C$animate.c$56$1_0$133	= .
	.globl	C$animate.c$56$1_0$133
;src/animate.c:56: }
	C$animate.c$56$1_0$133	= .
	.globl	C$animate.c$56$1_0$133
	XG$scanline_player_graphics_upload$0$0	= .
	.globl	XG$scanline_player_graphics_upload$0$0
	ret
	G$setPlayerFrameMap$0$0	= .
	.globl	G$setPlayerFrameMap$0$0
	C$animate.c$58$1_0$135	= .
	.globl	C$animate.c$58$1_0$135
;src/animate.c:58: void setPlayerFrameMap(uint8_t spritemap_index) {
;	---------------------------------
; Function setPlayerFrameMap
; ---------------------------------
_setPlayerFrameMap::
	add	sp, #-6
	ldhl	sp,	#4
	C$animate.c$62$3_0$137	= .
	.globl	C$animate.c$62$3_0$137
;src/animate.c:62: for (uint8_t i = 0; i < 8; i++) {
	ld	(hl+), a
	ld	(hl), #0x00
00123$:
	ldhl	sp,	#5
	ld	a, (hl)
	sub	a, #0x08
	jr	NC, 00101$
	C$animate.c$63$3_0$137	= .
	.globl	C$animate.c$63$3_0$137
;src/animate.c:63: player_tile_locations[i]=smtilesources[(spritemap_index<<3)+i]<<5;
	ld	a, (hl)
	ldhl	sp,	#0
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	inc	hl
	ld	(hl-), a
	ld	a, (hl+)
	inc	hl
	ld	(hl-), a
	sla	(hl)
	inc	hl
	rl	(hl)
	ld	de, #_player_tile_locations
	ld	a, (hl-)
	ld	l, (hl)
	ld	h, a
	add	hl, de
	ld	c, l
	ld	b, h
	ldhl	sp,	#4
	ld	e, (hl)
	ld	d, #0x00
	ld	a, e
	add	a, a
	rl	d
	add	a, a
	rl	d
	add	a, a
	rl	d
	ld	e, a
	pop	hl
	push	hl
	add	hl, de
	ld	e, l
	ld	d, h
	ld	hl, #_smtilesources
	add	hl, de
	ld	l, (hl)
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	e, l
	ld	d, h
	ld	a, e
	ld	(bc), a
	inc	bc
	ld	a, d
	ld	(bc), a
	C$animate.c$62$2_0$136	= .
	.globl	C$animate.c$62$2_0$136
;src/animate.c:62: for (uint8_t i = 0; i < 8; i++) {
	ldhl	sp,	#5
	inc	(hl)
	jr	00123$
00101$:
	C$animate.c$66$1_0$135	= .
	.globl	C$animate.c$66$1_0$135
;src/animate.c:66: if ((dub_buffer_counter & 1) == 0) {
	ld	a, (#_dub_buffer_counter)
	rrca
	jr	C, 00103$
;C:/Users/JennyR/Documents/Nikku4211Archive/GBA/GBDev/GBDK/include/gb/gb.h:1602: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 2)
	ld	(hl), #0x00
	ld	hl, #(_shadow_OAM + 6)
	ld	(hl), #0x02
	ld	hl, #(_shadow_OAM + 10)
	ld	(hl), #0x04
	ld	hl, #(_shadow_OAM + 14)
	ld	(hl), #0x06
	ld	hl, #(_shadow_OAM + 18)
	ld	(hl), #0x08
	ld	hl, #(_shadow_OAM + 22)
	ld	(hl), #0x0a
	ld	hl, #(_shadow_OAM + 26)
	ld	(hl), #0x0c
	ld	hl, #(_shadow_OAM + 30)
	ld	(hl), #0x0e
	C$animate.c$74$1_0$135	= .
	.globl	C$animate.c$74$1_0$135
;src/animate.c:74: set_sprite_tile(7, 14);
	jr	00134$
00103$:
;C:/Users/JennyR/Documents/Nikku4211Archive/GBA/GBDev/GBDK/include/gb/gb.h:1602: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 2)
	ld	(hl), #0x10
	ld	hl, #(_shadow_OAM + 6)
	ld	(hl), #0x12
	ld	hl, #(_shadow_OAM + 10)
	ld	(hl), #0x14
	ld	hl, #(_shadow_OAM + 14)
	ld	(hl), #0x16
	ld	hl, #(_shadow_OAM + 18)
	ld	(hl), #0x18
	ld	hl, #(_shadow_OAM + 22)
	ld	(hl), #0x1a
	ld	hl, #(_shadow_OAM + 26)
	ld	(hl), #0x1c
	ld	hl, #(_shadow_OAM + 30)
	ld	(hl), #0x1e
	C$animate.c$87$2_0$135	= .
	.globl	C$animate.c$87$2_0$135
;src/animate.c:87: for (uint8_t i = 0; i < 8; i++) {
00134$:
	ld	c, #0x00
00126$:
	ld	a, c
	sub	a, #0x08
	jr	NC, 00128$
	C$animate.c$88$3_0$141	= .
	.globl	C$animate.c$88$3_0$141
;src/animate.c:88: player_tile_y_offset[i]=smyoffsets[(spritemap_index<<3)+i];
	ld	de, #_player_tile_y_offset
	ld	l, c
	ld	h, #0x00
	add	hl, de
	push	hl
	ld	a, l
	ldhl	sp,	#4
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#3
	ld	(hl+), a
	ld	l, (hl)
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	e, c
	ld	d, #0x00
	add	hl, de
	ld	e, l
	ld	d, h
	ld	hl, #_smyoffsets
	add	hl, de
	ld	b, (hl)
	ldhl	sp,	#2
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	ld	(hl), b
	C$animate.c$87$2_0$140	= .
	.globl	C$animate.c$87$2_0$140
;src/animate.c:87: for (uint8_t i = 0; i < 8; i++) {
	inc	c
	jr	00126$
00128$:
	C$animate.c$90$2_0$135	= .
	.globl	C$animate.c$90$2_0$135
;src/animate.c:90: }
	add	sp, #6
	C$animate.c$90$2_0$135	= .
	.globl	C$animate.c$90$2_0$135
	XG$setPlayerFrameMap$0$0	= .
	.globl	XG$setPlayerFrameMap$0$0
	ret
	G$animatePlayer$0$0	= .
	.globl	G$animatePlayer$0$0
	C$animate.c$92$2_0$190	= .
	.globl	C$animate.c$92$2_0$190
;src/animate.c:92: void animatePlayer(){
;	---------------------------------
; Function animatePlayer
; ---------------------------------
_animatePlayer::
	dec	sp
	C$animate.c$93$1_0$190	= .
	.globl	C$animate.c$93$1_0$190
;src/animate.c:93: if (frame_rate_counter==0){
	ld	a, (#_frame_rate_counter)
	or	a, a
	jp	NZ, 00147$
	C$animate.c$99$1_0$190	= .
	.globl	C$animate.c$99$1_0$190
;src/animate.c:99: switch(player_animation_frame){
	ld	a, (#_player_animation_frame)
	or	a, a
	ld	a, #0x01
	jr	Z, 00297$
	xor	a, a
00297$:
	ld	b, a
	ld	a, (#_player_animation_frame)
	dec	a
	ld	a, #0x01
	jr	Z, 00299$
	xor	a, a
00299$:
	ldhl	sp,	#0
	ld	(hl), a
	ld	a, (#_player_animation_frame)
	sub	a, #0x02
	ld	a, #0x01
	jr	Z, 00301$
	xor	a, a
00301$:
	ld	d, a
	ld	a, (#_player_animation_frame)
	sub	a, #0x03
	ld	a, #0x01
	jr	Z, 00303$
	xor	a, a
00303$:
	ld	e, a
	C$animate.c$116$1_0$190	= .
	.globl	C$animate.c$116$1_0$190
;src/animate.c:116: } else if (player_direction == 1){
	ld	a, (#_player_direction)
	dec	a
	ld	a, #0x01
	jr	Z, 00305$
	xor	a, a
00305$:
	ld	c, a
	C$animate.c$95$2_0$191	= .
	.globl	C$animate.c$95$2_0$191
;src/animate.c:95: if (player_attack){
	ld	hl, #_player_attack
	bit	0, (hl)
	jp	Z, 00144$
	C$animate.c$96$3_0$192	= .
	.globl	C$animate.c$96$3_0$192
;src/animate.c:96: player_idle=FALSE;
	ld	hl, #_player_idle
	ld	(hl), #0x00
	C$animate.c$97$3_0$192	= .
	.globl	C$animate.c$97$3_0$192
;src/animate.c:97: frame_rate_divisor=3;
	ld	hl, #_frame_rate_divisor
	ld	(hl), #0x03
	C$animate.c$98$3_0$192	= .
	.globl	C$animate.c$98$3_0$192
;src/animate.c:98: if (player_direction == 0){
	ld	a, (#_player_direction)
	C$animate.c$99$4_0$193	= .
	.globl	C$animate.c$99$4_0$193
;src/animate.c:99: switch(player_animation_frame){
	or	a,a
	jr	NZ, 00116$
	or	a,b
	jr	NZ, 00101$
	ldhl	sp,	#0
	ld	a, (hl)
	or	a,a
	jr	NZ, 00102$
	or	a,d
	jr	NZ, 00103$
	or	a,e
	jr	NZ, 00104$
	jr	00105$
	C$animate.c$100$5_0$194	= .
	.globl	C$animate.c$100$5_0$194
;src/animate.c:100: case 0:
00101$:
	C$animate.c$101$5_0$194	= .
	.globl	C$animate.c$101$5_0$194
;src/animate.c:101: setPlayerFrameMap(playattackleft1);
	ld	a, #0x05
	call	_setPlayerFrameMap
	C$animate.c$102$5_0$194	= .
	.globl	C$animate.c$102$5_0$194
;src/animate.c:102: break;
	jp	00147$
	C$animate.c$103$5_0$194	= .
	.globl	C$animate.c$103$5_0$194
;src/animate.c:103: case 1:
00102$:
	C$animate.c$104$5_0$194	= .
	.globl	C$animate.c$104$5_0$194
;src/animate.c:104: setPlayerFrameMap(playattackleft2);
	ld	a, #0x06
	call	_setPlayerFrameMap
	C$animate.c$105$5_0$194	= .
	.globl	C$animate.c$105$5_0$194
;src/animate.c:105: break;
	jp	00147$
	C$animate.c$106$5_0$194	= .
	.globl	C$animate.c$106$5_0$194
;src/animate.c:106: case 2:
00103$:
	C$animate.c$107$5_0$194	= .
	.globl	C$animate.c$107$5_0$194
;src/animate.c:107: setPlayerFrameMap(playattackleft3);
	ld	a, #0x07
	call	_setPlayerFrameMap
	C$animate.c$108$5_0$194	= .
	.globl	C$animate.c$108$5_0$194
;src/animate.c:108: break;
	jp	00147$
	C$animate.c$109$5_0$194	= .
	.globl	C$animate.c$109$5_0$194
;src/animate.c:109: case 3:
00104$:
	C$animate.c$110$5_0$194	= .
	.globl	C$animate.c$110$5_0$194
;src/animate.c:110: setPlayerFrameMap(playattackleft3);
	ld	a, #0x07
	call	_setPlayerFrameMap
	C$animate.c$111$5_0$194	= .
	.globl	C$animate.c$111$5_0$194
;src/animate.c:111: player_attack = FALSE;
	ld	hl, #_player_attack
	ld	(hl), #0x00
	C$animate.c$112$5_0$194	= .
	.globl	C$animate.c$112$5_0$194
;src/animate.c:112: break;
	jp	00147$
	C$animate.c$113$5_0$194	= .
	.globl	C$animate.c$113$5_0$194
;src/animate.c:113: default:
00105$:
	C$animate.c$114$5_0$194	= .
	.globl	C$animate.c$114$5_0$194
;src/animate.c:114: setPlayerFrameMap(playattackleft1);
	ld	a, #0x05
	call	_setPlayerFrameMap
	C$animate.c$115$3_0$192	= .
	.globl	C$animate.c$115$3_0$192
;src/animate.c:115: }
	jp	00147$
00116$:
	C$animate.c$116$3_0$192	= .
	.globl	C$animate.c$116$3_0$192
;src/animate.c:116: } else if (player_direction == 1){
	ld	a, c
	or	a, a
	jp	Z, 00147$
	C$animate.c$117$4_0$195	= .
	.globl	C$animate.c$117$4_0$195
;src/animate.c:117: switch(player_animation_frame){
	ld	a, b
	or	a, a
	jr	NZ, 00107$
	ldhl	sp,	#0
	ld	a, (hl)
	or	a,a
	jr	NZ, 00108$
	or	a,d
	jr	NZ, 00109$
	or	a,e
	jr	NZ, 00110$
	jr	00111$
	C$animate.c$118$5_0$196	= .
	.globl	C$animate.c$118$5_0$196
;src/animate.c:118: case 0:
00107$:
	C$animate.c$119$5_0$196	= .
	.globl	C$animate.c$119$5_0$196
;src/animate.c:119: setPlayerFrameMap(playattackright1);
	ld	a, #0x0d
	call	_setPlayerFrameMap
	C$animate.c$120$5_0$196	= .
	.globl	C$animate.c$120$5_0$196
;src/animate.c:120: break;
	jp	00147$
	C$animate.c$121$5_0$196	= .
	.globl	C$animate.c$121$5_0$196
;src/animate.c:121: case 1:
00108$:
	C$animate.c$122$5_0$196	= .
	.globl	C$animate.c$122$5_0$196
;src/animate.c:122: setPlayerFrameMap(playattackright2);
	ld	a, #0x0e
	call	_setPlayerFrameMap
	C$animate.c$123$5_0$196	= .
	.globl	C$animate.c$123$5_0$196
;src/animate.c:123: break;
	jp	00147$
	C$animate.c$124$5_0$196	= .
	.globl	C$animate.c$124$5_0$196
;src/animate.c:124: case 2:
00109$:
	C$animate.c$125$5_0$196	= .
	.globl	C$animate.c$125$5_0$196
;src/animate.c:125: setPlayerFrameMap(playattackright3);
	ld	a, #0x0f
	call	_setPlayerFrameMap
	C$animate.c$126$5_0$196	= .
	.globl	C$animate.c$126$5_0$196
;src/animate.c:126: break;
	jp	00147$
	C$animate.c$127$5_0$196	= .
	.globl	C$animate.c$127$5_0$196
;src/animate.c:127: case 3:
00110$:
	C$animate.c$128$5_0$196	= .
	.globl	C$animate.c$128$5_0$196
;src/animate.c:128: setPlayerFrameMap(playattackright3);
	ld	a, #0x0f
	call	_setPlayerFrameMap
	C$animate.c$129$5_0$196	= .
	.globl	C$animate.c$129$5_0$196
;src/animate.c:129: player_attack = FALSE;
	ld	hl, #_player_attack
	ld	(hl), #0x00
	C$animate.c$130$5_0$196	= .
	.globl	C$animate.c$130$5_0$196
;src/animate.c:130: break;
	jp	00147$
	C$animate.c$131$5_0$196	= .
	.globl	C$animate.c$131$5_0$196
;src/animate.c:131: default:
00111$:
	C$animate.c$132$5_0$196	= .
	.globl	C$animate.c$132$5_0$196
;src/animate.c:132: setPlayerFrameMap(playattackright1);
	ld	a, #0x0d
	call	_setPlayerFrameMap
	C$animate.c$133$2_0$191	= .
	.globl	C$animate.c$133$2_0$191
;src/animate.c:133: }
	jp	00147$
00144$:
	C$animate.c$137$3_0$197	= .
	.globl	C$animate.c$137$3_0$197
;src/animate.c:137: if (player_move_left) {
	ld	hl, #_player_move_left
	bit	0, (hl)
	jr	Z, 00141$
	C$animate.c$138$4_0$198	= .
	.globl	C$animate.c$138$4_0$198
;src/animate.c:138: player_idle = FALSE;
	ld	hl, #_player_idle
	ld	(hl), #0x00
	C$animate.c$139$4_0$198	= .
	.globl	C$animate.c$139$4_0$198
;src/animate.c:139: frame_rate_divisor=6;
	ld	hl, #_frame_rate_divisor
	ld	(hl), #0x06
	C$animate.c$140$4_0$198	= .
	.globl	C$animate.c$140$4_0$198
;src/animate.c:140: switch(player_animation_frame){
	ld	a, b
	or	a, a
	jr	NZ, 00118$
	ldhl	sp,	#0
	ld	a, (hl)
	or	a,a
	jr	NZ, 00119$
	or	a,d
	jr	NZ, 00120$
	or	a,e
	jr	NZ, 00121$
	jr	00122$
	C$animate.c$141$5_0$199	= .
	.globl	C$animate.c$141$5_0$199
;src/animate.c:141: case 0:
00118$:
	C$animate.c$142$5_0$199	= .
	.globl	C$animate.c$142$5_0$199
;src/animate.c:142: setPlayerFrameMap(playwalkleft1);
	ld	a, #0x01
	call	_setPlayerFrameMap
	C$animate.c$143$5_0$199	= .
	.globl	C$animate.c$143$5_0$199
;src/animate.c:143: break;
	jp	00147$
	C$animate.c$144$5_0$199	= .
	.globl	C$animate.c$144$5_0$199
;src/animate.c:144: case 1:
00119$:
	C$animate.c$145$5_0$199	= .
	.globl	C$animate.c$145$5_0$199
;src/animate.c:145: setPlayerFrameMap(playwalkleft2);
	ld	a, #0x02
	call	_setPlayerFrameMap
	C$animate.c$146$5_0$199	= .
	.globl	C$animate.c$146$5_0$199
;src/animate.c:146: break;
	jp	00147$
	C$animate.c$147$5_0$199	= .
	.globl	C$animate.c$147$5_0$199
;src/animate.c:147: case 2:
00120$:
	C$animate.c$148$5_0$199	= .
	.globl	C$animate.c$148$5_0$199
;src/animate.c:148: setPlayerFrameMap(playwalkleft3);
	ld	a, #0x03
	call	_setPlayerFrameMap
	C$animate.c$149$5_0$199	= .
	.globl	C$animate.c$149$5_0$199
;src/animate.c:149: break;
	jp	00147$
	C$animate.c$150$5_0$199	= .
	.globl	C$animate.c$150$5_0$199
;src/animate.c:150: case 3:
00121$:
	C$animate.c$151$5_0$199	= .
	.globl	C$animate.c$151$5_0$199
;src/animate.c:151: setPlayerFrameMap(playwalkleft4);
	ld	a, #0x04
	call	_setPlayerFrameMap
	C$animate.c$152$5_0$199	= .
	.globl	C$animate.c$152$5_0$199
;src/animate.c:152: break;
	jr	00147$
	C$animate.c$153$5_0$199	= .
	.globl	C$animate.c$153$5_0$199
;src/animate.c:153: default:
00122$:
	C$animate.c$154$5_0$199	= .
	.globl	C$animate.c$154$5_0$199
;src/animate.c:154: setPlayerFrameMap(playwalkleft1);
	ld	a, #0x01
	call	_setPlayerFrameMap
	C$animate.c$155$3_0$197	= .
	.globl	C$animate.c$155$3_0$197
;src/animate.c:155: }
	jr	00147$
00141$:
	C$animate.c$156$3_0$197	= .
	.globl	C$animate.c$156$3_0$197
;src/animate.c:156: } else if (player_move_right) {
	ld	hl, #_player_move_right
	bit	0, (hl)
	jr	Z, 00138$
	C$animate.c$157$4_0$200	= .
	.globl	C$animate.c$157$4_0$200
;src/animate.c:157: player_idle = FALSE;
	ld	hl, #_player_idle
	ld	(hl), #0x00
	C$animate.c$158$4_0$200	= .
	.globl	C$animate.c$158$4_0$200
;src/animate.c:158: frame_rate_divisor=6;
	ld	hl, #_frame_rate_divisor
	ld	(hl), #0x06
	C$animate.c$159$4_0$200	= .
	.globl	C$animate.c$159$4_0$200
;src/animate.c:159: switch(player_animation_frame){
	ld	a, b
	or	a, a
	jr	NZ, 00124$
	ldhl	sp,	#0
	ld	a, (hl)
	or	a,a
	jr	NZ, 00125$
	or	a,d
	jr	NZ, 00126$
	or	a,e
	jr	NZ, 00127$
	jr	00128$
	C$animate.c$160$5_0$201	= .
	.globl	C$animate.c$160$5_0$201
;src/animate.c:160: case 0:
00124$:
	C$animate.c$161$5_0$201	= .
	.globl	C$animate.c$161$5_0$201
;src/animate.c:161: setPlayerFrameMap(playwalkright1);
	ld	a, #0x09
	call	_setPlayerFrameMap
	C$animate.c$162$5_0$201	= .
	.globl	C$animate.c$162$5_0$201
;src/animate.c:162: break;
	jr	00147$
	C$animate.c$163$5_0$201	= .
	.globl	C$animate.c$163$5_0$201
;src/animate.c:163: case 1:
00125$:
	C$animate.c$164$5_0$201	= .
	.globl	C$animate.c$164$5_0$201
;src/animate.c:164: setPlayerFrameMap(playwalkright2);
	ld	a, #0x0a
	call	_setPlayerFrameMap
	C$animate.c$165$5_0$201	= .
	.globl	C$animate.c$165$5_0$201
;src/animate.c:165: break;
	jr	00147$
	C$animate.c$166$5_0$201	= .
	.globl	C$animate.c$166$5_0$201
;src/animate.c:166: case 2:
00126$:
	C$animate.c$167$5_0$201	= .
	.globl	C$animate.c$167$5_0$201
;src/animate.c:167: setPlayerFrameMap(playwalkright3);
	ld	a, #0x0b
	call	_setPlayerFrameMap
	C$animate.c$168$5_0$201	= .
	.globl	C$animate.c$168$5_0$201
;src/animate.c:168: break;
	jr	00147$
	C$animate.c$169$5_0$201	= .
	.globl	C$animate.c$169$5_0$201
;src/animate.c:169: case 3:
00127$:
	C$animate.c$170$5_0$201	= .
	.globl	C$animate.c$170$5_0$201
;src/animate.c:170: setPlayerFrameMap(playwalkright4);
	ld	a, #0x0c
	call	_setPlayerFrameMap
	C$animate.c$171$5_0$201	= .
	.globl	C$animate.c$171$5_0$201
;src/animate.c:171: break;
	jr	00147$
	C$animate.c$172$5_0$201	= .
	.globl	C$animate.c$172$5_0$201
;src/animate.c:172: default:
00128$:
	C$animate.c$173$5_0$201	= .
	.globl	C$animate.c$173$5_0$201
;src/animate.c:173: setPlayerFrameMap(playwalkright1);
	ld	a, #0x09
	call	_setPlayerFrameMap
	C$animate.c$174$3_0$197	= .
	.globl	C$animate.c$174$3_0$197
;src/animate.c:174: } 
	jr	00147$
00138$:
	C$animate.c$177$4_0$202	= .
	.globl	C$animate.c$177$4_0$202
;src/animate.c:177: if (player_direction == 1 && player_idle == FALSE) {
	ld	a, c
	or	a, a
	jr	Z, 00134$
	ld	hl, #_player_idle
	bit	0, (hl)
	jr	NZ, 00134$
	C$animate.c$178$5_0$203	= .
	.globl	C$animate.c$178$5_0$203
;src/animate.c:178: setPlayerFrameMap(playidleright);
	ld	a, #0x08
	call	_setPlayerFrameMap
	C$animate.c$179$5_0$203	= .
	.globl	C$animate.c$179$5_0$203
;src/animate.c:179: player_idle = TRUE;
	ld	hl, #_player_idle
	ld	(hl), #0x01
	jr	00147$
00134$:
	C$animate.c$180$4_0$202	= .
	.globl	C$animate.c$180$4_0$202
;src/animate.c:180: } else if (player_direction == 0 && player_idle == FALSE) {
	ld	a, (#_player_direction)
	or	a, a
	jr	NZ, 00147$
	ld	hl, #_player_idle
	bit	0, (hl)
	jr	NZ, 00147$
	C$animate.c$181$5_0$204	= .
	.globl	C$animate.c$181$5_0$204
;src/animate.c:181: setPlayerFrameMap(playidleleft);
	xor	a, a
	call	_setPlayerFrameMap
	C$animate.c$182$5_0$204	= .
	.globl	C$animate.c$182$5_0$204
;src/animate.c:182: player_idle = TRUE;
	ld	hl, #_player_idle
	ld	(hl), #0x01
00147$:
	C$animate.c$188$1_0$190	= .
	.globl	C$animate.c$188$1_0$190
;src/animate.c:188: if (player_animation_frame < 4) {
	ld	a, (#_player_animation_frame)
	sub	a, #0x04
	jr	NC, 00152$
	C$animate.c$189$2_0$205	= .
	.globl	C$animate.c$189$2_0$205
;src/animate.c:189: if (frame_rate_counter > 0) {
	ld	hl, #_frame_rate_counter
	ld	a, (hl)
	or	a, a
	jr	Z, 00149$
	C$animate.c$190$3_0$206	= .
	.globl	C$animate.c$190$3_0$206
;src/animate.c:190: frame_rate_counter--;
	dec	(hl)
	jr	00154$
00149$:
	C$animate.c$192$3_0$207	= .
	.globl	C$animate.c$192$3_0$207
;src/animate.c:192: frame_rate_counter = frame_rate_divisor;
	ld	a, (#_frame_rate_divisor)
	ld	(#_frame_rate_counter),a
	C$animate.c$193$3_0$207	= .
	.globl	C$animate.c$193$3_0$207
;src/animate.c:193: player_animation_frame++;
	ld	hl, #_player_animation_frame
	inc	(hl)
	jr	00154$
00152$:
	C$animate.c$196$2_0$208	= .
	.globl	C$animate.c$196$2_0$208
;src/animate.c:196: player_animation_frame = 0;
	ld	hl, #_player_animation_frame
	ld	(hl), #0x00
00154$:
	C$animate.c$198$1_0$190	= .
	.globl	C$animate.c$198$1_0$190
;src/animate.c:198: }
	inc	sp
	C$animate.c$198$1_0$190	= .
	.globl	C$animate.c$198$1_0$190
	XG$animatePlayer$0$0	= .
	.globl	XG$animatePlayer$0$0
	ret
	G$setEnemyFrameMap$0$0	= .
	.globl	G$setEnemyFrameMap$0$0
	C$animate.c$200$1_0$210	= .
	.globl	C$animate.c$200$1_0$210
;src/animate.c:200: void setEnemyFrameMap(unsigned char enemy_frame_map[]) {
;	---------------------------------
; Function setEnemyFrameMap
; ---------------------------------
_setEnemyFrameMap::
	add	sp, #-3
	ld	c, e
	ld	b, d
	C$animate.c$204$2_0$210	= .
	.globl	C$animate.c$204$2_0$210
;src/animate.c:204: for (uint8_t i = 0; i < 4; i++) {
	ldhl	sp,	#2
	ld	(hl), #0x00
00105$:
	ldhl	sp,	#2
	ld	a, (hl)
	sub	a, #0x04
	jr	NC, 00101$
;src/animate.c:205: set_sprite_tile(i+8, enemy_frame_map[(i<<2)]+32);
	ld	e, (hl)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, bc
	ld	a, (hl)
	add	a, #0x20
	ld	e, a
	ldhl	sp,	#2
	ld	a, (hl)
	add	a, #0x08
	ld	d, a
;C:/Users/JennyR/Documents/Nikku4211Archive/GBA/GBDev/GBDK/include/gb/gb.h:1602: shadow_OAM[nb].tile=tile;
	ld	l, d
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	push	de
	ld	de, #_shadow_OAM
	add	hl, de
	inc	hl
	inc	hl
	pop	de
	ld	(hl), e
	C$animate.c$204$2_0$211	= .
	.globl	C$animate.c$204$2_0$211
;src/animate.c:204: for (uint8_t i = 0; i < 4; i++) {
	ldhl	sp,	#2
	inc	(hl)
	jr	00105$
00101$:
	C$animate.c$210$3_0$214	= .
	.globl	C$animate.c$210$3_0$214
;src/animate.c:210: for (uint8_t i = 0; i < 8; i++) {
	ldhl	sp,	#2
	ld	(hl), #0x00
00108$:
	ldhl	sp,	#2
	ld	a, (hl)
	sub	a, #0x08
	jr	NC, 00110$
	C$animate.c$211$3_0$214	= .
	.globl	C$animate.c$211$3_0$214
;src/animate.c:211: enemy_tile_y_offset[i]=enemy_frame_map[(i<<2)+1];
	ld	de, #_enemy_tile_y_offset
	ld	l, (hl)
	ld	h, #0x00
	add	hl, de
	inc	sp
	inc	sp
	push	hl
	ldhl	sp,	#2
	ld	l, (hl)
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	inc	hl
	add	hl, bc
	ld	a, (hl)
	pop	hl
	push	hl
	ld	(hl), a
	C$animate.c$210$2_0$213	= .
	.globl	C$animate.c$210$2_0$213
;src/animate.c:210: for (uint8_t i = 0; i < 8; i++) {
	ldhl	sp,	#2
	inc	(hl)
	jr	00108$
00110$:
	C$animate.c$213$2_0$210	= .
	.globl	C$animate.c$213$2_0$210
;src/animate.c:213: }
	add	sp, #3
	C$animate.c$213$2_0$210	= .
	.globl	C$animate.c$213$2_0$210
	XG$setEnemyFrameMap$0$0	= .
	.globl	XG$setEnemyFrameMap$0$0
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
