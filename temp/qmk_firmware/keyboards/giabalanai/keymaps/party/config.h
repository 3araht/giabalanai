#pragma once


/* PARTY_REACTIVE_FOCUSED_MODE
 * Enable 'RGB_MATRIX_CUSTOM_USER = yes' in rules.mk when below is enabled.
 * Or vice versa in order to shrink the firmware size. */
// #define PARTY_REACTIVE_FOCUSED_MODE

#ifdef PARTY_REACTIVE_FOCUSED_MODE

// #   define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #   define DISABLE_RGB_MATRIX_RAINBOW_BEACON

#   ifdef DISABLE_RGB_MATRIX_MULTISPLASH
#       undef DISABLE_RGB_MATRIX_MULTISPLASH
#   endif
#   ifdef DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#       undef DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#   endif
#   ifdef DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#       undef DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#   endif

#endif
