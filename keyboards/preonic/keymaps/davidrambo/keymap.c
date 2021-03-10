#include QMK_KEYBOARD_H

//aliases for clarity in layering
#define KC_A_BSPC  LALT(KC_BSPC) // delete whole word in Mac
#define KC_C_BSPC  LCTL(KC_BSPC) // delete whole word in PC
#define KC_A_LEFT  LALT(KC_LEFT)
#define KC_A_RGHT  LALT(KC_RGHT)
#define KC_C_RGHT  LCTL(KC_RGHT)
#define KC_C_LEFT  LCTL(KC_LEFT)
#define KC_SftEnt  SFT_T(KC_ENT)
#define KC_BS_GUI  LGUI_T(KC_BSPC)
#define KC_BS_CTL  LCTL_T(KC_BSPC)
#define KC_RECT    LCA_T(KC_DEL) // Ctrl+Alt is the basis for Rectangle WM

// internet browser tab shortcuts and window/application swapping for Mac and Win
#define KC_GSL     LGUI(S(KC_LEFT)) // back one tab in Safari
#define KC_GSR     LGUI(S(KC_RGHT)) // forward one tab in Safari
#define KC_CTLPGUP LCTL(KC_PGUP)   // back one tab on PC
#define KC_CTLPGDN LCTL(KC_PGDN)   // forward one tab on PC
#define KC_G_TAB   LGUI(KC_TAB)    // Mac: switch applications
#define KC_G_GRV   LGUI(KC_GRV)    // Mac: switch between windows within an application
#define KC_A_TAB   LALT(KC_TAB)
#define KC_C_TAB   LCTL(KC_TAB)

// navigKC_ation layers for both Mac OS X and Windows
#define KC_NAVMAC  LT(5, KC_ESC)
#define KC_NAVPC   LT(6, KC_ESC)
#define KC_NAVQUD  LT(7, KC_ESC)

#define _COLEMAK 0
#define _PC 1
#define _QUD 2
#define _GAME 3
#define _SYMBOL 4
#define _NAVMAC 5
#define _NAVPC 6
#define _NAVQUD 7

//tapdance declarations
enum {
  SFT_LCK
};

#define KC_SftLck TD(SFT_LCK) /* alias for tapdance */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ESC` |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SftLck|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |  /?  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |PrnSc | GUI  | Alt  | Ctrl |BsGui | Space|Symbol| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
*/

[_COLEMAK] = LAYOUT_preonic_grid( \
  KC_GRV    , KC_1,    KC_2,    KC_3,    KC_4,    KC_5  ,    KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    TG(1)  , \
  KC_TAB    , KC_Q,    KC_W,    KC_F,    KC_P,    KC_G  ,    KC_J,   KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_NAVMAC , KC_A,    KC_R,    KC_S,    KC_T,    KC_D  ,    KC_H,   KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_SftLck , KC_Z,    KC_X,    KC_C,    KC_V,    KC_B  ,    KC_K,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_SftEnt, \
  KC_RECT   , KC_RCTL, KC_LGUI, KC_LCTL, KC_LALT, KC_BS_GUI, KC_SPC, MO(4),  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),
  
[_PC] = LAYOUT_preonic_grid( \
  _______ , _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, TO(2)  , \
  _______ , _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
  KC_NAVPC, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
  _______ , _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, \
  KC_DEL  , KC_PSCR, KC_LCTL, KC_LALT, KC_LGUI, KC_BS_CTL, KC_SPC,  MO(4),   _______, _______, _______, _______
  ),
  
[_QUD] = LAYOUT_preonic_grid( \
  _______  , _______, _______, _______, _______, _______  , _______, _______, _______, _______, _______, TO(3)  , \
  _______  , _______, _______, _______, _______, _______  , _______, _______, _______, _______, _______, _______, \
  KC_NAVQUD, _______, _______, _______, _______, _______  , _______, _______, _______, _______, _______, _______, \
  _______  , _______, _______, _______, _______, _______  , _______, _______, _______, _______, _______, _______, \
  KC_DEL   , KC_PSCR, KC_LGUI, KC_LALT, KC_LCTL, KC_NAVQUD, KC_SPC,  MO(4)  , _______, _______, _______, _______
  ),

[_GAME] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(0)  , \
  KC_TAB , KC_T   , KC_Q   , KC_W   , KC_E   , KC_R   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , _______, \
  KC_TAB , KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, _______, \
  KC_LALT, KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_N   , KC_M   , _______, _______, _______, _______, \
  _______, _______, _______, KC_G   , KC_B   , KC_SPC , KC_I   , MO(4)  , _______, _______, _______, _______
  ),

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |   [  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   ]  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  \|  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  =+  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Home | End  |      | Play | BRMD | BRMU |  -_  |Pg Up |      |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  `~  |      |      |      |      |      |      |      |Pg Dn | Vol- | Vol+ |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_preonic_grid(
  KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , \
  KC_LBRC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_RBRC, \
  KC_BSLS, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL , \
  _______, KC_HOME, KC_END , KC_MNXT, KC_MPLY, KC_WH_L, KC_WH_R, KC_MINS, KC_PGUP, KC_WH_D, KC_WH_U, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_VOLD, KC_VOLU, KC_MUTE 
  ),

/* Navigation*/

[_NAVMAC] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______   , _______  , _______, _______  , _______ , _______, \
  _______, _______, _______, _______, _______, _______, KC_C_TAB  , KC_A_LEFT, KC_UP  , KC_A_RGHT, KC_DEL  , _______, \
  _______, _______, _______, _______, _______, _______, S(KC_C_TAB),KC_LEFT  , KC_DOWN, KC_RGHT  , KC_C_TAB, _______, \
  _______, _______, _______, _______, _______, _______, KC_G_TAB  , KC_A_BSPC, KC_HOME, KC_END   , KC_G_GRV, _______, \
  RESET  , _______, _______, _______, KC_RALT, _______, _______   , _______  , _______, _______  , _______ , _______
),

[_NAVPC] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______   , _______  , _______, _______  , _______   , _______, \
    _______, _______, _______, _______, _______, _______, KC_C_TAB  , KC_C_LEFT, KC_UP  , KC_C_RGHT, KC_DEL    , _______, \
    _______, _______, _______, _______, _______, _______, KC_CTLPGUP, KC_LEFT  , KC_DOWN, KC_RGHT  , KC_CTLPGDN, _______, \
    _______, _______, _______, _______, _______, _______, KC_A_TAB  , KC_C_BSPC, KC_HOME, KC_END   , KC_G_GRV  , _______, \
    RESET  , _______, _______, KC_RALT, _______, _______, _______   , _______  , _______, _______  , _______   , _______
),
  
[_NAVQUD] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PSLS, KC_PAST, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_P7  , KC_P8  , KC_P9  , _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_P4  , KC_P2  , KC_P6  , _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_P1  , KC_P5  , KC_P3  , _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PMNS, KC_PPLS, _______, _______
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
