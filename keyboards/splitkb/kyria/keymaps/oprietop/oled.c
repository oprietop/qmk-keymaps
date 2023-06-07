#ifdef OLED_ENABLE
static char       keylog_str[6] = {};
static uint16_t   log_timer = 0;
static const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};
static const char PROGMEM logo[] = {
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,192,192,224,224,224,224,112,112,112,112, 56, 56, 56, 56, 56, 28, 28, 28, 28, 28, 28, 28, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 28, 28, 28, 28, 28, 28, 28, 56, 56, 56, 56, 56,112,112,112,112,224,224,224,224,192,192,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,192,224,240,112,120, 56, 60, 28, 30, 14, 15,  7,  7,  3,  3,  3,  1,  1,  1,  0,  0,  0,  0,128,192,192,224,240,248,248,252,252,252,254,254,254,255,255,255,127, 15,  1,  0,  0,  0,128,192,224,240,248,252,252,254,254,254,252,248,240,  0,  0,  0,  0,  0,  0,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,192,192,  0,  0,  1,  1,  1,  3,  3,  3,  7,  7, 15, 14, 30, 28, 60, 56,120,112,240,224,192,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,128,224,240,248, 60, 30, 15,  7,  3,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,240,248,254,255,127, 31, 15,  7,  3,225,252,255,255,255,255,255,255,255, 31,  3,  0,128,224,248,252,255,255,255,255,255, 63, 15,  7,  3,  1,241,255,255,255,  0,  0,  0,192,248,255,255,255,255,255,255,255, 31,  3,  0,  0,  0,  1,255,255,255,255,255,255,255,255,120,  0,  0,  0,128,192,224,240,248,252,254,254,254,254,254,252,120, 56,145,129,195,199,143, 30, 60,248,240,224,192,  0,  0,
  0,128,252,255,255, 15,  1,  0,  0,  0,128,192,192,224,224,240,240,240,240,240,240,240,240,240,240,240,240,240,252,255,255,255,255,247,243,240,240,240,240,248,255,255,255,255,255,255,255, 63,  7,  0,128,240,254,255,255,255,255,255,127, 15,  3,  0,  0,  0,192,240,254,255, 63,  7,  0,128,240,254,255,255,255,255,255,255, 63,  7,  0,  0,  0,192,240,248,255,255,255,255,255,255,127, 31,135,192,240,248,254,255,127, 63,255,255,255,255,255,255,255,255,192,128, 15, 13, 31, 27, 31, 13, 15,  0,  0,  1,
  15,255,255,252,192,  1, 63,255,255,224,128,  0,  0,254,255,255,255,255,255,255,255,231,195,195,195,195,195,243,255,255,255,255, 63,  7,  3,  3,  3,  3,  3,131,243,255,255,255,255,255,255,255,127, 15,  1,  0,  0,248,255,255,255,255,255,255,255,143,192,224,240,252,126, 63, 15,  7,  1,  0,  0,224,252,255,255,255,255,255,255,255,239,113,120,248,252,190,191,223,223,207,239,231,243,123,249,188,222,223,239,231,227,227,225,240,240,240,240,243,255,255,255,255,255,255,255,255,255,188,128,  0,  0,  0,  0,  0,
  0,128,224,255,255, 63,  3,  0,  0,  0,  3,  7, 31, 62,124,248,243,227,199,143, 15, 31, 31, 31, 31, 31, 31, 31, 31, 15, 15,  7,  1,  0,  0,  0,  0,  0,128,240,254,255,255,255,255,255,255,255,159,195,192,192,224,224,240,255,255,255,255,255,255,255,255,199,195,195,193,224,224,240,112,120,252,252,255,255,255,255,255,255,255,143,199,199,199,199,199,195,195,195,  3,  3,  1,  1,  1,  0, 28, 63,127,123,115,241,241,241,241,240,248,121,125,125,127,127, 63, 63, 63, 31, 31, 15, 15, 31, 31, 63,255,255,255,254,254,124,
  62, 31,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  7,  7, 15, 30, 28, 60, 56,120,112,240,224,224,192,192,192,128,128,128, 28, 31, 31, 31, 15, 15, 15, 15, 15,  7,  7,  7,  3,  3,  3,  1,  1,  1,  3, 15, 15, 15, 15, 15, 15, 15,  7,  7,  7,  3,  1,  1,192,248,255,127, 63, 63, 31, 31, 15, 15,  7,  7, 63, 63, 63, 31, 31, 15, 15, 15, 14, 62, 62, 62, 62, 62, 62, 58, 24, 16,  0,  0,  0,  0,  0,  0,128,128,128,192,192,192,224,224,240,112,120, 56, 60, 28, 30, 15,  7,  7,  3,  1,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  3,  3,  7,  7,  7, 15, 14, 14, 14, 30, 28, 28, 28, 28, 56, 56, 56, 56, 56, 56,112,112,112,112,112,112,112,112,112,112, 96, 96,224,224,224,227,225,224,224,224,224,224,224, 96, 96,112,112,112,112,112,112,112,112,112, 56, 56, 56, 56, 56, 56, 28, 28, 28, 28, 30, 14, 14, 14, 15,  7,  7,  7,  3,  3,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_180;
}

void add_keylog(uint16_t keycode) {
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
    keycode = keycode & 0xFF;
  }
  for (uint8_t i = 4; i > 0; --i) {
    keylog_str[i] = keylog_str[i - 1];
  }
  if (keycode < 60) {
    keylog_str[0] = code_to_name[keycode];
  }
  log_timer = timer_read();
}

void update_log(void) {
  if (timer_elapsed(log_timer) > 750) {
    add_keylog(0);
  }
}

void render_default_layer_state(void) {
  oled_write_P(PSTR("    BASE: "), false);
  switch (biton32(default_layer_state)) {
    case _QW:
      oled_write_P(PSTR("Qwerty     "), false);
      break;
    case _DH:
      oled_write_P(PSTR("ModDH      "), false);
      break;
    case _DV:
      oled_write_P(PSTR("Dvorak     "), false);
      break;
  }
}

void render_layer_state(void) {
  oled_write_P(PSTR("   LAYER: "), false);
  switch (biton32(layer_state)) {
    case 0:
      oled_write_P(PSTR("Default    "), false);
      break;
    case _RA:
      oled_write_P(PSTR("Raise      "), false);
      break;
    case _LO:
      oled_write_P(PSTR("Lower      "), false);
      break;
    case _AD:
      oled_write_P(PSTR("Adjust     "), false);
      break;
    case _EM:
      oled_write_P(PSTR("Emoji      "), false);
      break;
    default:
      oled_write_P(PSTR("Unknown    "), false);
      break;
  }
}

void render_keylock_status(uint8_t led_usb_state) {
//  oled_write_P(PSTR("LOCKS:    "), false);
  oled_write_P(PSTR("  NUM  "), led_usb_state & (1 << USB_LED_NUM_LOCK));
  oled_write_P(PSTR(" CAPS "), led_usb_state & (1 << USB_LED_CAPS_LOCK));
  oled_write_P(PSTR("  SCR   "), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
}

void render_mod_status(uint8_t modifiers) {
//  oled_write_P(PSTR("MODS:     /n"), false);
  oled_write_P(PSTR(" SFT "), (modifiers & MOD_MASK_SHIFT));
  oled_write_P(PSTR(" CTR "), (modifiers & MOD_MASK_CTRL));
  oled_write_P(PSTR(" GUI "), (modifiers & MOD_MASK_GUI));
  oled_write_P(PSTR(" ALT  "), (modifiers & MOD_MASK_ALT));
  oled_write_P(PSTR("                     "), false);
}

void render_keylogger_status(void) {
  oled_write_P(PSTR("LOG: "), false);
  oled_write(keylog_str, false);
  oled_write_P(PSTR(" "), false);
}

void render_banner(void) {
  oled_write_P(PSTR("    <Kyria v1.3>     "), false);
}

void render_wpm(void) {
  uint8_t n = get_current_wpm();
  char wpm_counter[4];
  wpm_counter[3] = '\0';
  wpm_counter[2] = '0' + n % 10;
  wpm_counter[1] = (n /= 10) % 10 ? '0' + (n) % 10 : (n / 10) % 10 ? '0' : ' ';
  wpm_counter[0] = n / 10 ? '0' + n / 10 : ' ';
  oled_write_P(PSTR("WPM: "), false);
  oled_write(wpm_counter, false);
  oled_write_P(PSTR("  "), false);
}

void render_logo(void) {
  oled_write_raw_P(logo, sizeof(logo));
}

void render_status_secondary(void) {
  render_logo();
  //oled_scroll_left(); // Turns on scrolling
}

void render_status_main(void) {
  render_banner();
  //render_bootmagic_status();
  render_default_layer_state();
  render_layer_state();
  render_keylock_status(host_keyboard_leds());
  render_mod_status(get_mods());
  render_wpm();
  render_keylogger_status();
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status_main();
    } else {
        render_status_secondary();
    }
    return false;
}
#endif
