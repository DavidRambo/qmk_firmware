#include QMK_KEYBOARD_H

//layer shorthands
#define _COLEMAK 0
#define _PC 1
#define _GAME 2
#define _SYMBOL 3
#define _NAVMAC 4
#define _NAVPC 5

//keycode shorthands
#define ___  KC_TRNS // three underscores "___" for transparent
#define SYM  MO(3)
#define MAC  TO(0)
// #define PC   TO(1)
#define GM   TO(2)
// #define NAVMAC LT(4, KC_TAB)
// #define NAVPC  LT(5, KC_TAB)

//text editor shortcuts for NAV and NAVPC
#define AL   LALT(KC_LEFT)
#define AR   LALT(KC_RGHT)
#define CL   LCTL(KC_LEFT)
#define CR   LCTL(KC_RGHT)
#define ABSPC LALT(KC_BSPC)
#define CBSPC LCTL(KC_BSPC)

//internet browser tab shortcuts and window swapping for Mac and Windows
#define GSL  LGUI(S(KC_LEFT))
#define GSR  LGUI(S(KC_RGHT))
#define CPGD LCTL(KC_PGDN)
#define CPGU LCTL(KC_PGUP)

#define CMBS  GUI_T(KC_BSPC)
#define CTBS  CTL_T(KC_BSPC)
#define C_TAB LCTL(KC_TAB)
#define G_TAB LGUI(KC_TAB)
#define A_TAB LALT(KC_TAB)

//#define SFLK TD(SFT_LCK)     // alias for tapdance

enum custom_keycodes {
//	SFT_LCK //tapdance declarations
    COLEMAK = 0,
    PC,
    GAME,
    SYMBOL,
    NAV, //Navigation layer for Mac Colemak
    NAVPC, //Navigation layer for PC Colemak
//    SFT_LCK //tapdance declaration
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = LAYOUT(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,        KC_6, KC_7, KC_8, KC_9, KC_0,KC_MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     KC_GRV, KC_Q, KC_W, KC_F, KC_P, KC_G,       KC_J, KC_L, KC_U, KC_Y,KC_SCLN,KC_BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
   LT(4, KC_TAB), KC_A, KC_R, KC_S, KC_T, KC_D,         KC_H, KC_N, KC_E, KC_I, KC_O,KC_QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
    KC_LSFT, KC_Z, KC_X, KC_C,KC_V,KC_B, TO(1),  KC_ENT, KC_K, KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                    KC_LCTL,KC_LALT,CMBS,    KC_SPC, SYM, KC_RALT
  //                  `----+----+----'        `----+----+----'
  ),

    [_PC] = LAYOUT(
    ___ , ___ , ___ , ___ , ___ , ___ ,          ___ , ___ , ___ , ___ , ___ , ___ ,
        
    ___ , ___ , ___ , ___ , ___ , ___ ,          ___ , ___ , ___ , ___ , ___ , ___ ,
        
    LT(5, KC_TAB),___ , ___ , ___ , ___ , ___ ,          ___ , ___ , ___ , ___ , ___ , ___ ,
        
    ___ , ___ , ___ , ___ , ___ , ___ , GM, ___, ___ , ___ , ___ , ___ , ___ , ___ , 
        
                      KC_LALT,KC_LGUI , CTBS ,    ___ , ___ , ___ 
    ),
   
    [_GAME] = LAYOUT(
    ___ , ___ , ___ , ___ , ___ , ___ ,          ___ , ___ , ___ , ___ , ___ , ___ ,
        
    KC_B,KC_T, KC_Q, KC_W, KC_E, KC_R,          ___ , ___ , ___ , ___ , ___ , ___ ,
        
    KC_TAB, KC_LSFT, KC_A, KC_S, KC_D, KC_F,          ___ , ___ , ___ , ___ , ___ , ___ ,
        
    KC_LALT, KC_LCTL,KC_Z,KC_X,KC_C,KC_V,KC_M,KC_P , ___, ___ , ___ , ___ , ___ , ___ , 
        
                          KC_G, KC_I, KC_SPC,    KC_BSPC, MAC, ___ 
    ), 
    
    [_SYMBOL] = LAYOUT(
    
    KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,              KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    
    KC_LBRC, KC_1, KC_2, KC_3, KC_4, KC_5,                  KC_6, KC_7, KC_8, KC_9, KC_0, KC_RBRC,
        
    KC_BSLS, KC_EXLM, KC_AT, KC_HASH, KC_DLR,               KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL,
        
    ___, KC_HOME, KC_END, KC_VOLD, KC_VOLU, KC_MPLY, ___,   ___,___, KC_MINS, ___ , ___ , ___ , ___ , 
        
                        ___ , ___ , ___,                        ___, ___ , ___ 
    ),
   
    [_NAVMAC] = LAYOUT(
    
    RESET,___ , ___ , ___ , ___ , ___ ,         ___ , ___ , ___ , ___ , ___ , ___ ,
        
    ___ , ___ , ___ , ___ , ___ , ___ ,         C_TAB, AL, KC_UP,  AR , KC_DEL , ___ ,
        
    ___ , ___ , ___ , ___ , ___ , ___ ,         GSL , KC_LEFT, KC_DOWN, KC_RGHT, GSR , ___ ,
        
    ___ , ___ , ___ , ___ , ___ , ___ ,___,  ___,G_TAB,ABSPC, ___ , ___ , ___ , ___ , 
        
                        ___ , ___ , ___ ,       ___ , ___ , ___ 
    ),
    
    [_NAVPC] = LAYOUT(
    
    RESET,___ , ___ , ___ , ___ , ___ ,         ___ , ___ , ___ , ___ , ___ , ___ ,
        
    ___ , ___ , ___ , ___ , ___ , ___ ,         C_TAB, CL , KC_UP ,  CR , KC_DEL , ___ ,
        
    ___ , ___ , ___ , ___ , ___ , ___ ,         CPGU, KC_LEFT, KC_DOWN, KC_RGHT, CPGD, ___ ,
        
    ___ , ___ , ___ , ___ , ___ , ___ ,___,  ___,A_TAB,CBSPC, ___ , ___ , ___ , ___ , 
        
                        ___ , ___ , ___ ,       ___ , ___ , ___ 
    ),
   
};

// Shift vs. capslock function. From bbaserdem's Planck keymap (since deprecated).
/*void caps_tap (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_LSFT);
    } else if (state->count == 2) {
        unregister_code (KC_LSFT);
        register_code (KC_CAPS);
    }
}
void caps_tap_end (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_LSFT);
    } else {
        unregister_code (KC_CAPS);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    //Tap once for Shift, twice for Caps Lock
    [SFT_LCK] = ACTION_TAP_DANCE_FN_ADVANCED( caps_tap, NULL, caps_tap_end)
};
*/