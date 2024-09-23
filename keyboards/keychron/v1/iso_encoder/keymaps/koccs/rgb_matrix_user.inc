RGB_MATRIX_EFFECT(gaming_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

uint8_t calculateColorWithBrightness(uint8_t color, uint8_t brightness, uint8_t factor) {
    return color * (brightness / factor) / 255;
}

static bool gaming_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  if (!rgb_matrix_get_flags()) {
    rgb_matrix_set_color_all(0, 0, 0);
    return rgb_matrix_check_finished_leds(led_max);
  }

  uint8_t brightness = rgb_matrix_get_val();

  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, calculateColorWithBrightness(255, brightness, 16), calculateColorWithBrightness(255, brightness, 16), calculateColorWithBrightness(255, brightness, 16));
  }

  uint8_t moveButtons[] = {
    32, // W
    45, // A
    46, // S
    47, // D
    76, // Space
  };
  for (uint8_t i = 0; i < sizeof(moveButtons) / sizeof(moveButtons[0]); i++) {
    rgb_matrix_set_color(moveButtons[i], calculateColorWithBrightness(255, brightness, 3), calculateColorWithBrightness(6, brightness, 3), 0);
  }

  uint8_t letterButtons[] = {
    31, // Q
    33, // E
    48, // F
    62, // X
    63, // C
    67, // M
  };
  for (uint8_t i = 0; i < sizeof(letterButtons) / sizeof(letterButtons[0]); i++) {
    rgb_matrix_set_color(letterButtons[1], calculateColorWithBrightness(255, brightness, 3), calculateColorWithBrightness(192, brightness, 3), 0);
  }

  uint8_t numberButtons[] = {
    15, // `
    16, // 1
    17, // 2
    18, // 3
    19, // 4
    20, // 5
  };
  for (uint8_t i = 0; i < sizeof(numberButtons) / sizeof(numberButtons[0]); i++) {
    rgb_matrix_set_color(numberButtons[1], 0, calculateColorWithBrightness(22, brightness, 3), calculateColorWithBrightness(255, brightness, 3));
  }

  uint8_t modifierButtons[] = {
    30, // Tab
    59, // Shift
    73, // Ctrl
    75, // Alt
  };
  for (uint8_t i = 0; i < sizeof(modifierButtons) / sizeof(modifierButtons[0]); i++) {
    rgb_matrix_set_color(modifierButtons[1], calculateColorWithBrightness(11, brightness, 3), calculateColorWithBrightness(255, brightness, 3), 0);
  }

  rgb_matrix_set_color(34, calculateColorWithBrightness(255, brightness, 3), 0, calculateColorWithBrightness(255, brightness, 3)); // R

  return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
