#pragma once

#define MASTER_RIGHT
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 3000  // 3 seconds.

#define TAPPING_TERM 210
/*#define PERMISSIVE_HOLD*/
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

#ifdef RGB_MATRIX_ENABLE
    #define rgb_disable_when_usb_suspended  // turn off effects when suspended
#endif
