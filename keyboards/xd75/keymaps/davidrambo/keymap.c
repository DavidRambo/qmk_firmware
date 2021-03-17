#include QMK_KEYBOARD_H

//aliases for clarity in layering
#define A_BSPC  LALT(KC_BSPC) // delete whole word in Mac
#define C_BSPC  LCTL(KC_BSPC) // delete whole word in PC
#define A_LEFT  LALT(KC_LEFT)
#define A_RGHT  LALT(KC_RGHT)
#define C_RGHT  LCTL(KC_RGHT)
#define C_LEFT  LCTL(KC_LEFT)
#define SftEnt  SFT_T(KC_ENT)
#define BS_GUI  LGUI_T(KC_BSPC)
#define BS_CTL  LCTL_T(KC_BSPC)
#define VOLU KC__VOLUP
#define VOLD KC__VOLDOWN

// internet browser tab shortcuts and window/application swapping for Mac and Win
#define GSL     LGUI(S(KC_LEFT)) // back one tab in Safari
#define GSR     LGUI(S(KC_RGHT)) // forward one tab in Safari
#define CTLPGDN LCTL(KC_PGDN)   // back one tab on Windows
#define CTLPGUP LCTL(KC_PGUP)   // forward one tab on Windows
#define G_TAB   LGUI(KC_TAB)    // Mac: switch applications
#define G_GRV   LGUI(KC_GRV)    // Mac: switch between windows within an application
#define A_TAB   LALT(KC_TAB)
#define C_TAB   LCTL(KC_TAB)

// navigation layers for both Mac OS X and Windows
#define NAV     LT(5, KC_TAB)
#define NAVPC   LT(6, KC_TAB)
#define NAVQUD  MO(7)

// Layer shorthand
#define _COLEMAK 0
#define _PC 1
#define _GAME 2     // Gaming layer
#define _QUD  3
#define _SYMBOL 4   // Function keys, numbers, symbols, Backlighting
#define _NAV 5   // Navigation Layer on Mac
#define _NAVPC 6 // Navigation Layer on Win
#define _NAVQUD 7

// tapdance declarations
enum {
  SFT_LCK
};

// alias for tapdance
#define SftLck TD(SFT_LCK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `~     | 1      | 2      | 3      | 4      | 5      | -_     |   PC   | =+     | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | ESC/`~ | Q      | W      | F      | P      | G      | [      |   \|   | ]      | J      | L      | U      | Y      | ;      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | NAVTAB | A      | S      | D      | F      | G      | PgUp   |PlayPaus| ENTER  | H      | N      | E      | I      | O      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |SFT/CAPS| Z      | X      | C      | V      | B      | PgDn   |  UP    | ENTER  | K      | M      | ,      | .      | /      | SftEnt |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | DEL    | LGUI   | LCTRL  | LALT   | LGUI   | BKSPC  | LEFT   | DOWN   | RIGHT  | SPACE  | SYMBOL | RGUI   | RALT   | RCTRL  | BL     |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_COLEMAK] = LAYOUT_ortho_5x15( /* COLEMAK */
   KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_MINS, TO(1)  , KC_EQL,  KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC,
   KC_GESC, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,   KC_LBRC, KC_BSLS, KC_RBRC, KC_J,   KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
   NAV    , KC_A,    KC_R,    KC_S,    KC_T,    KC_D,   KC_PGUP, KC_MPLY, KC_ENT , KC_H,   KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT,
   SftLck , KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_PGDN, KC_UP  , KC_ENT , KC_K,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, SftEnt ,
   KC_DEL , KC_LGUI, KC_LCTL, KC_LALT, KC_LCTL, BS_GUI, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC, MO(4) , KC_RGUI, KC_RALT, KC_RCTL, BL_STEP
 ),
    
// Windows Layer: essentially swaps Control and GUI

 [_PC] = LAYOUT_ortho_5x15( /* WINDOWS */
   _______, _______, _______, _______, _______, _______, _______, TO(2)  , _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   NAVPC  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, KC_LCTL, KC_LGUI, _______, KC_LGUI, BS_CTL , _______, _______, _______, _______, _______, KC_RCTL, _______, KC_RGUI, _______
 ),

 [_GAME] = LAYOUT_ortho_5x15( /* Gaming Layer */
   _______, _______, _______, _______, _______, _______, _______, TO(0)  , _______, _______, _______, _______, _______, _______, TO(3)  ,
   KC_ESC , KC_T   , KC_Q   , KC_W   , KC_E   , KC_R   , KC_F7  , KC_F8  , KC_F9  , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , _______,
   KC_TAB , KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_F4  , KC_F5  , KC_F6  , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, _______,
   KC_LALT, KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_F1  , KC_F2  , KC_F3  , KC_N   , KC_M   , _______, _______, _______, KC_ENT ,
   _______, _______, _______, KC_G   , KC_B   , KC_SPC , KC_I   , KC_M   , _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______
 ),
  
   [_QUD] = LAYOUT_ortho_5x15( /* Roguelike Layer */
   _______, _______, _______, _______, _______, _______, _______,KC_PSLS, KC_PAST, _______, _______, _______, _______, _______, TO(0)  ,
   KC_GESC, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,   KC_LBRC, KC_BSLS, KC_RBRC, KC_J,   KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
   NAV    , KC_A,    KC_R,    KC_S,    KC_T,    KC_D,   KC_PGUP, KC_MPLY, KC_ENT , KC_H,   KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT,
   SftLck , KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_PGDN, KC_UP  , KC_ENT , KC_K,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, SftEnt ,
   KC_DEL , KC_LGUI, KC_LGUI, KC_LALT, KC_LCTL, MO(7),  KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC, MO(4) , KC_RGUI, KC_RALT, KC_RCTL, _______
 ),
    
/* SYMBOL
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F12    | F1     | F2     | F3     | F4     | F5     |        |        |        | F6     | F7     | F8     | F9     | F10    | F11    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | [{     | 1      | 2      | 3      | 4      | 5      |        |        |        | 6      | 7      | 8      | 9      | 0      | }]     |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | !      | @      | #      | $      | %      |        |        |        | ^      | &      | *      | (      | )      | =      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | HOME   | END    | BL_OFF | BL_ON  |        |        |        |        |        | -_     |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_SYMBOL] = LAYOUT_ortho_5x15( /* SYMBOL */
   KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______, _______, _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
   KC_LBRC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______, _______, _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_RBRC,
   _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL ,
   _______, KC_HOME, KC_END , BL_OFF , BL_ON  , VOLD   , _______, _______, _______, VOLU   , KC_MINS, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),

 
 [_NAV] = LAYOUT_ortho_5x15( /* NAVIGATION for Mac */
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, C_TAB  , A_LEFT,  KC_UP,   A_RGHT , KC_DEL , _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, S(C_TAB),KC_LEFT, KC_DOWN, KC_RGHT, C_TAB  , _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, G_TAB  , A_BSPC , KC_HOME, KC_END , G_GRV  , _______,
   RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),

 [_NAVPC] = LAYOUT_ortho_5x15( /* NAVIGATION FOR WINDOWS: replaces Alt with Control, GUI with Alt, and browser tab shortcuts*/
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, C_TAB  , C_LEFT,  KC_UP,   C_RGHT , KC_DEL , _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, CTLPGUP, KC_LEFT, KC_DOWN, KC_RGHT, CTLPGDN, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, A_TAB  , C_BSPC , KC_HOME, KC_END , _______, _______,
   RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),
    
 [_NAVQUD] = LAYOUT_ortho_5x15( /* NAVIGATION for Mac */
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSLS, KC_PAST, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_2, KC_KP_6, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_5, KC_KP_3, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_0, KC_PMNS, KC_PPLS, _______, _______
 )
};

// Shift vs capslock function. From bbaserdem's Planck keymap.
void caps_tap (qk_tap_dance_state_t *state, void *user_data) {
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

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Shift, twice for Caps Lock
  [SFT_LCK] = ACTION_TAP_DANCE_FN_ADVANCED( caps_tap, NULL, caps_tap_end )
};

/* Template for future layers
 [_LAYER_NAME] = { 
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
 }
};
*/
