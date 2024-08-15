#include QMK_KEYBOARD_H

enum custom_layers {
    _COLEMAK,
    _RL, // Layer for roguelikes, pairs with a numpad on _NAVRL
    _GAME,
    _SYMBOL,
    _NAVIGATION,
    _NAVRL,
    _FKEYS,
};

//keycode shorthands
#define SYM  MO(3)
#define SPCSYM LT(3, KC_SPC)
#define NAV  LT(4, KC_ESC)
#define FKEY MO(6)

//aliases for clarity in layering
#define SftEnt  SFT_T(KC_ENT)   // Shift when held, Enter when tapped
#define BSCTL   LCTL_T(KC_BSPC) // Ctrl when held, Backspace when tapped

//aliases for clarity in layering
#define C_TAB   LCTL(KC_TAB)
#define A_TAB   LALT(KC_TAB)
#define G_TAB   LGUI(KC_TAB)    // Mac: switch applications

#define CBSPC   LCTL(KC_BSPC)  // delete whole word
#define G_LEFT  LGUI(KC_LEFT)
#define G_RGHT  LGUI(KC_RGHT)
#define CRGHT   LCTL(KC_RGHT)
#define CLEFT   LCTL(KC_LEFT)

// Left-hand home row mods
#define HOME_A LALT_T(KC_A)
#define HOME_R LGUI_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LGUI_T(KC_I)
#define HOME_O LALT_T(KC_O)

//internet browser tab shortcuts and window swapping
#define CTLPGDN LCTL(KC_PGDN)
#define CTLPGUP LCTL(KC_PGUP)

#define G_GRV   LGUI(KC_GRV)
#define SftEnt  SFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,    KC_6,  KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,  KC_Q,    KC_W,   KC_F,    KC_P,    KC_G,    KC_J,  KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  NAV,     HOME_A,  HOME_R, HOME_S,  HOME_T,  KC_D,    KC_H,  HOME_N, HOME_E,  HOME_I,  HOME_O,  KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_K,  KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_DEL,  KC_RALT, FKEY,   KC_LALT, KC_LGUI, BSCTL, SPCSYM,  SYM,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

 [_RL] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, TG(5)  , _______, _______, _______, _______, _______, _______
),

 [_GAME] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(0)  ,
  KC_ESC , KC_T   , KC_Q   , KC_W   , KC_E   , KC_R   , _______, _______, _______, _______, _______, _______,
  KC_TAB , KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , _______, _______, _______, _______, _______, _______,
  KC_LALT, KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_G   , KC_B   , KC_SPC , _______, _______, _______, _______, _______, _______
),

[_SYMBOL] = LAYOUT_preonic_grid(
    KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9 ,  KC_F10 , KC_F11 ,
    KC_LBRC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9  ,  KC_0   , KC_RBRC,
    KC_BSLS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL ,
    _______, KC_HOME, KC_END , KC_LBRC, KC_RBRC, KC_B   , KC_GRV , KC_MINS, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE
),

 [_NAVIGATION] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, _______, C_TAB  , CLEFT  ,  KC_UP , CRGHT  , KC_DEL , _______,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, CTLPGUP, KC_LEFT, KC_DOWN, KC_RGHT, CTLPGDN, _______,
  _______, _______, _______, KC_WH_U, KC_WH_D, KC_MPLY, A_TAB  , CBSPC  , _______, _______, G_GRV  , _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

 [_NAVRL] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P0  , KC_PSLS, KC_PAST, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P7  , KC_P8  , KC_P9  , _______,
  _______, _______, _______, _______, _______, _______, _______, KC_PMNS, KC_P4  , KC_P2  , KC_P6  , KC_PPLS,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P1  , KC_P5  , KC_P3  , _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

 [_FKEYS] = LAYOUT_preonic_grid(
  QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(1)  , // Roguelike layer
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(2)  , // Game (WASD) layer
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(0)  , // Colemak layer
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};
