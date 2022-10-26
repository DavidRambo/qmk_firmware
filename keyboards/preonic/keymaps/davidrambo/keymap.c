/* Copyright 2021 David Rambo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

//aliases for clarity in layering
#define A_BSPC  LALT(KC_BSPC) // delete whole word in Mac
#define C_BSPC  LCTL(KC_BSPC) // delete whole word in PC
#define A_LEFT  LALT(KC_LEFT) // move cursor whole word back in Mac
#define A_RGHT  LALT(KC_RGHT) // move cursor whole word forward in Mac
#define C_RGHT  LCTL(KC_RGHT) // move cursor whole word back in PC
#define C_LEFT  LCTL(KC_LEFT) // move cursor whole word forward in PC
#define SftEnt  SFT_T(KC_ENT)
#define BS_GUI  LGUI_T(KC_BSPC)
#define BS_CTL  LCTL_T(KC_BSPC)
#define MEHDEL  MEH_T(KC_DEL)

// internet browser tab shortcuts and window/application swapping for Mac and Win
#define GSL     LGUI(S(KC_LEFT)) // back one tab in Safari
#define GSR     LGUI(S(KC_RGHT)) // forward one tab in Safari
#define CTLPGUP LCTL(KC_PGUP)   // back one tab on PC
#define CTLPGDN LCTL(KC_PGDN)   // forward one tab on PC
#define G_TAB   LGUI(KC_TAB)    // Mac: switch applications
#define G_GRV   LGUI(KC_GRV)    // Mac: switch between windows within an application
#define A_TAB   LALT(KC_TAB)
#define C_TAB   LCTL(KC_TAB)

// Left-hand home row mods
#define HOME_A LALT_T(KC_A)
#define HOME_R LGUI_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

// Swap for macos
#define MHOME_A LGUI_T(KC_A)
#define MHOME_R LALT_T(KC_R)

// Right-hand home row mods
#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LGUI_T(KC_I)
#define HOME_O LALT_T(KC_O)

// Swap for macos
#define MHOME_I LALT_T(KC_I)
#define MHOME_O LGUI_T(KC_O)

// navigKC_ation layers for both Mac OS X and Windows
#define NAVMAC  LT(5, KC_ESC)
#define NAVPC   LT(6, KC_ESC)
#define NAVQUD  LT(7, KC_ESC)

enum custom_layers {
    _COLEMAK,
    _PC, 
    _QUD,
    _GAME,
    _SYMBOL,
    _NAVMAC,
    _NAVPC,
    _NAVQUD,
};

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

[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5  , KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    TG(1)  ,
  KC_TAB , KC_Q,    KC_W,    KC_F,    KC_P,    KC_G  , KC_J,   KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  NAVMAC , HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_D  , KC_H,   HOME_N, HOME_E,  HOME_I,  HOME_O,  KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B  , KC_K,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, SftEnt ,
  MEHDEL , KC_RCTL, KC_LGUI, KC_LCTL, KC_LALT, BS_GUI, KC_SPC, MO(4),  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),
  
[_PC] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(2)  ,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  NAVPC  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_DEL , KC_PSCR, KC_LCTL, KC_LALT, KC_LGUI, BS_CTL , KC_SPC ,  MO(4) , _______, _______, _______, _______
  ),
  
[_QUD] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(3)  ,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  NAVQUD , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_DEL , KC_PSCR, KC_LGUI, KC_LALT, KC_LCTL, NAVQUD , KC_SPC,  MO(4)  , _______, _______, _______, _______
  ),

[_GAME] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(0)  ,
  KC_TAB , KC_T   , KC_Q   , KC_W   , KC_E   , KC_R   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , _______,
  KC_TAB , KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, _______,
  KC_LALT, KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_N   , KC_M   , _______, _______, _______, _______,
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
  KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
  KC_LBRC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_RBRC,
  KC_BSLS, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL ,
  _______, KC_HOME, KC_END , KC_LBRC, KC_RBRC, KC_MPLY, _______, KC_MINS, KC_PGUP, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_VOLD, KC_VOLU, KC_MUTE 
  ),

/* Navigation*/

[_NAVMAC] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, _______, C_TAB  , A_LEFT , KC_UP  , A_RGHT , KC_DEL , _______,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,S(C_TAB), KC_LEFT, KC_DOWN, KC_RGHT, C_TAB  , _______,
  _______, _______, _______, KC_WH_U, KC_WH_D, _______, G_TAB  , A_BSPC , KC_HOME, KC_END , G_GRV  , _______,
  QK_BOOT, _______, _______, _______, KC_RALT, _______, _______, _______, _______, _______, _______, _______
),

[_NAVPC] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, _______, C_TAB  , C_LEFT , KC_UP  , C_RGHT , KC_DEL , _______,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, CTLPGUP, KC_LEFT, KC_DOWN, KC_RGHT, CTLPGDN, _______,
    _______, _______, _______, KC_WH_U, KC_WH_D, _______, A_TAB  , C_BSPC , KC_HOME, KC_END , G_GRV  , _______,
    QK_BOOT, _______, _______, KC_RALT, _______, _______, _______, _______, _______, _______, _______, _______
),
  
[_NAVQUD] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PSLS, KC_PAST, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_P7  , KC_P8  , KC_P9  , _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_P4  , KC_P2  , KC_P6  , _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_P1  , KC_P5  , KC_P3  , _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PMNS, KC_PPLS, _______, _______
)
};
