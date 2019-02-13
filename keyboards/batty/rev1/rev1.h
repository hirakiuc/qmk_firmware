#pragma once

#include "../crkbd.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"

#ifdef RGBLIGHT_ENABLE
//rgb led driver
#include "ws2812.h"
#endif

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

//void promicro_bootloader_jmp(bool program);
#define LAYOUT( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25, L26, R26, R20, R21, R22, R23, R24, R25, \
  L33,                L30, L31, L32, R30, R31, R32,                R33 \
  ) \
  { \
    { L00, L01,   L02,   L03, L04, L05, KC_NO }, \
    { L10, L11,   L12,   L13, L14, L15, KC_NO }, \
    { L20, L21,   L22,   L23, L24, L25, KC_NO }, \
    { L33, KC_NO, KC_NO, L30, L31, L32, L26 }, \
    { R05, R04,   R03,   R02, R01, R00, KC_NO }, \
    { R15, R14,   R13,   R12, R11, R10, KC_NO }, \
    { R25, R24,   R23,   R22, R21, R20, KC_NO }, \
    { R33, KC_NO, KC_NO, R32, R31, R30, R26 } \
  }

#define LAYOUT_bt( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25, L26, R26, R20, R21, R22, R23, R24, R25, \
  L33,                L30, L31, L32, R30, R31, R32,                R33 \
  ) \
  LAYOUT( \
    KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05,                     KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, KC_##R05, \
    KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15,                     KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, \
    KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25, KC_##L26, KC_##R26, KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, KC_##R25, \
    KC_##L33,                               KC_##L30, KC_##L31, KC_##L32, KC_##R30, KC_##R31, KC_##R32,                               KC_##R33 \
  )
