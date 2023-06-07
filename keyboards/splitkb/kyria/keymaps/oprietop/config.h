#pragma once

/* Select hand configuration */
#define MASTER_LEFT

#define FORCE_NKRO

// Better latency
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 12

/* Fix for bad promicros  */
//#define SPLIT_USB_DETECT
//#define SPLIT_USB_TIMEOUT 2500

/* Macro and tapping behaviour */
#define TAPPING_TERM 150
#define IGNORE_MOD_TAP_INTERRUPT
//#define PERMISSIVE_HOLD
//#define TAPPING_FORCE_HOLD

#ifdef UNICODE_ENABLE
#  define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
#endif

#ifdef RGBLIGHT_ENABLE
#  undef RGBLED_NUM
#  define RGBLED_NUM 54
#  undef RGBLED_SPLIT
#  define RGBLED_SPLIT {27, 27}
#  define RGBLIGHT_HUE_STEP 8
#  define RGBLIGHT_SAT_STEP 8
#  define RGBLIGHT_VAL_STEP 5
#  define RGBLIGHT_LIMIT_VAL 120
#  define RGBLIGHT_ANIMATIONS
#endif

#ifdef RGB_MATRIX_ENABLE
#  define RGB_DISABLE_WHEN_USB_SUSPENDED false // turn off effects when suspended
#  define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120    // limits maximum brightness of LEDs. If not defined maximum brightness is set to 255
#  define RGB_MATRIX_HUE_STEP 8
#  define RGB_MATRIX_SAT_STEP 8
#  define RGB_MATRIX_VAL_STEP 5
#  define RGB_MATRIX_SPD_STEP 10
#  define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
#  define ENABLE_RGB_MATRIX_ALPHAS_MODS            // Static dual hue, speed is hue for secondary hue
#  define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN       // Static gradient top to bottom, speed controls how much gradient changes
#  define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT    // Static gradient left to right, speed controls how much gradient changes
#  define ENABLE_RGB_MATRIX_BREATHING              // Single hue brightness cycling animation
#  define ENABLE_RGB_MATRIX_BAND_SAT               // Single hue band fading saturation scrolling left to right
#  define ENABLE_RGB_MATRIX_BAND_VAL               // Single hue band fading brightness scrolling left to right
#  define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT      // Single hue 3 blade spinning pinwheel fades saturation
#  define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL      // Single hue 3 blade spinning pinwheel fades brightness
#  define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT        // Single hue spinning spiral fades saturation
#  define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL        // Single hue spinning spiral fades brightness
#  define ENABLE_RGB_MATRIX_CYCLE_ALL              // Full keyboard solid hue cycling through full gradient
#  define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT       // Full gradient scrolling left to right
#  define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN          // Full gradient scrolling top to bottom
#  define ENABLE_RGB_MATRIX_CYCLE_OUT_IN           // Full gradient scrolling out to in
//#  define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL      // Full dual gradients scrolling out to in
#  define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON // Full gradent Chevron shapped scrolling left to right
#  define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL         // Full gradient spinning pinwheel around center of keyboard
#  define ENABLE_RGB_MATRIX_CYCLE_SPIRAL           // Full gradient spinning spiral around center of keyboard
#  define ENABLE_RGB_MATRIX_DUAL_BEACON            // Full gradient spinning around center of keyboard
#  define ENABLE_RGB_MATRIX_RAINBOW_BEACON         // Full tighter gradient spinning around center of keyboard
#  define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS      // Full dual gradients spinning two halfs of keyboard
//#  define ENABLE_RGB_MATRIX_RAINDROPS              // Randomly changes a single key's hue
//#  define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS    // Randomly changes a single key's hue and saturation
//#  define ENABLE_RGB_MATRIX_HUE_BREATHING          // Hue shifts up a slight ammount at the same time, then shifts back
//#  define ENABLE_RGB_MATRIX_HUE_PENDULUM           // Hue shifts up a slight ammount in a wave to the right, then back to the left
//#  define ENABLE_RGB_MATRIX_HUE_WAVE               // Hue shifts up a slight ammount and then back down in a wave to the right
//#  define ENABLE_RGB_MATRIX_PIXEL_FRACTAL          // Single hue fractal filled keys pulsing horizontally out to edges
//#  define ENABLE_RGB_MATRIX_PIXEL_FLOW             // Pulsing RGB flow along LED wiring with random hues
//#  define ENABLE_RGB_MATRIX_PIXEL_RAIN             // Randomly light keys with random hues
#  undef RGB_MATRIX_FRAMEBUFFER_EFFECTS
#  ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP // How hot is your WPM!
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN   // That famous computer simulation
#  endif
#  undef RGB_MATRIX_KEYPRESSES // reacts to keypresses
#  ifdef RGB_MATRIX_KEYPRESSES
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE     // Pulses keys hit to hue & value then fades value out
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE            // Static single hue, pulses keys hit to shifted hue then fades to current hue
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#    define ENABLE_RGB_MATRIX_SPLASH                    // Full gradient & value pulse away from a single key hit then fades value out
#    define ENABLE_RGB_MATRIX_MULTISPLASH               // Full gradient & value pulse away from multiple key hits then fades value out
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH              // Hue & value pulse away from a single key hit then fades value out
#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH         // Hue & value pulse away from multiple key hits then fades value out
#  endif
#endif // RGB_MATRIX_ENABLE

#ifdef OLED_ENABLE
//#  define OLED_DISABLE_TIMEOUT
//#  define OLED_FONT_H "keyboards/crkbd/keymaps/oprietop/danger.c"
//#  define OLED_FONT_H "keyboards/crkbd/keymaps/oprietop/alps.c"
#endif

/* Mouse Settings */
#ifdef MOUSEKEY_ENABLE
#  define MOUSEKEY_INTERVAL 16
#  define MOUSEKEY_DELAY 0
#  define MOUSEKEY_TIME_TO_MAX 60
#  define MOUSEKEY_MAX_SPEED 7
#  define MOUSEKEY_WHEEL_DELAY 0
#  define MOUSEKEY_WHEEL_MAX_SPEED 2
#  define MOUSEKEY_WHEEL_TIME_TO_MAX 6
#endif

/* Disable unused and unneeded features to reduce on firmware size */
#ifdef LOCKING_SUPPORT_ENABLE
#   undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#   undef LOCKING_RESYNC_ENABLE
#endif

/* Get more spacce if uning less than 8 layeer */
#define LAYER_STATE_8BIT
#define NO_ACTION_ONESHOT
