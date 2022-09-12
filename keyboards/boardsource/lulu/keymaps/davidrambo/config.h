#pragma once

#define MASTER_RIGHT
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 3000  // 3 seconds.

#ifdef RGB_MATRIX_ENABLE
    #define rgb_disable_when_usb_suspended  // turn off effects when suspended
#endif
