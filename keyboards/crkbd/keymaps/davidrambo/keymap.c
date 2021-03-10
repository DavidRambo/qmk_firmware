#include QMK_KEYBOARD_H

extern uint8_t is_master;

#define _COLEMAK 0
#define _SYMBOL 1
#define _NAVIGATION 2
#define _FKEYS 3

//keycode shorthands
#define KC_SYM  MO(1)
#define KC_NAV  LT(2, KC_ESC)
#define KC_FKEY MO(3)

//aliases for clarity in layering
#define KC_SftEnt SFT_T(KC_ENT)
#define KC_BSCTL  LCTL_T(KC_BSPC)
#define KC_CTAB   LCTL(KC_TAB)
#define KC_ATAB   LALT(KC_TAB)

//aliases for Navigation layer
#define KC_CBSPC LCTL(KC_BSPC) // delete whole word in PC
#define KC_CL   LCTL(KC_LEFT)
#define KC_CR   LCTL(KC_RGHT)

//internet browser tab shortcuts and window swapping for Mac and Windows
#define KC_CPGD LCTL(KC_PGDN)
#define KC_CPGU LCTL(KC_PGUP)

#define G_GRV   LGUI(KC_GRV)
#define SftEnt  SFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_NAV  ,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                        KC_H,    KC_N,    KC_E,    KC_I, KC_O   , KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_SftEnt,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, KC_LGUI, KC_BSCTL,   KC_SPC,   KC_SYM, KC_FKEY \
                                      //`--------------------------'  `--------------------------'

  ),

  [_SYMBOL] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LBRC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_RBRC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSLS, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL ,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HOME, KC_END,  _______, _______, _______,                       KC_GRV, KC_MINS, KC_PGUP, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, KC_PGDN \
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAVIGATION] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      KC_CTAB,   KC_CL,   KC_UP,   KC_CR,  KC_DEL, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_CPGU, KC_LEFT, KC_DOWN, KC_RGHT, KC_CPGD, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_ATAB, KC_CBSPC, KC_HOME, KC_END, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, KC_RALT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_FKEYS] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______,  _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, KC_VOLD, KC_VOLU, KC_MPLY,                     _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,      RESET, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  )
};
