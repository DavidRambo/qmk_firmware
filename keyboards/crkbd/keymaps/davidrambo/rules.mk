# My Corne's left hand has an Elite-C, whereas the right hand has a micro-usb.
# This bootloader does not pick up the latter when trying to flash the right side.
# (This was required when I recently reflashed in order to get the right hand LEDs to work.)
# To flash the right side, plug in a micro-usb and run:
# $ make crkbd:davidrambo:avrdude-split-right

BOOTLOADER = atmel-dfu
