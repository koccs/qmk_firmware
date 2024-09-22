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

  rgb_matrix_set_color(32, calculateColorWithBrightness(255, brightness, 3), calculateColorWithBrightness(6, brightness, 3), 0); // W
  rgb_matrix_set_color(45, calculateColorWithBrightness(255, brightness, 3), calculateColorWithBrightness(6, brightness, 3), 0); // A
  rgb_matrix_set_color(46, calculateColorWithBrightness(255, brightness, 3), calculateColorWithBrightness(6, brightness, 3), 0); // S
  rgb_matrix_set_color(47, calculateColorWithBrightness(255, brightness, 3), calculateColorWithBrightness(6, brightness, 3), 0); // D
  rgb_matrix_set_color(76, calculateColorWithBrightness(255, brightness, 3), calculateColorWithBrightness(6, brightness, 3), 0); // Space

  rgb_matrix_set_color(31, calculateColorWithBrightness(255, brightness, 3), calculateColorWithBrightness(192, brightness, 3), 0); // Q
  rgb_matrix_set_color(33, calculateColorWithBrightness(255, brightness, 3), calculateColorWithBrightness(192, brightness, 3), 0); // E
  rgb_matrix_set_color(48, calculateColorWithBrightness(255, brightness, 3), calculateColorWithBrightness(192, brightness, 3), 0); // F
  rgb_matrix_set_color(62, calculateColorWithBrightness(255, brightness, 3), calculateColorWithBrightness(192, brightness, 3), 0); // X
  rgb_matrix_set_color(63, calculateColorWithBrightness(255, brightness, 3), calculateColorWithBrightness(192, brightness, 3), 0); // C
  rgb_matrix_set_color(67, calculateColorWithBrightness(255, brightness, 3), calculateColorWithBrightness(192, brightness, 3), 0); // M

  rgb_matrix_set_color(34, calculateColorWithBrightness(255, brightness, 3), 0, calculateColorWithBrightness(255, brightness, 3)); // R

  rgb_matrix_set_color(30, calculateColorWithBrightness(11, brightness, 3), calculateColorWithBrightness(255, brightness, 3), 0); // Tab
  rgb_matrix_set_color(59, calculateColorWithBrightness(11, brightness, 3), calculateColorWithBrightness(255, brightness, 3), 0); // Shift
  rgb_matrix_set_color(73, calculateColorWithBrightness(11, brightness, 3), calculateColorWithBrightness(255, brightness, 3), 0); // Ctrl
  rgb_matrix_set_color(75, calculateColorWithBrightness(11, brightness, 3), calculateColorWithBrightness(255, brightness, 3), 0); // Alt

  rgb_matrix_set_color(15, 0, calculateColorWithBrightness(22, brightness, 3), calculateColorWithBrightness(255, brightness, 3)); // `
  rgb_matrix_set_color(16, 0, calculateColorWithBrightness(22, brightness, 3), calculateColorWithBrightness(255, brightness, 3)); // 1
  rgb_matrix_set_color(17, 0, calculateColorWithBrightness(22, brightness, 3), calculateColorWithBrightness(255, brightness, 3)); // 2
  rgb_matrix_set_color(18, 0, calculateColorWithBrightness(22, brightness, 3), calculateColorWithBrightness(255, brightness, 3)); // 3
  rgb_matrix_set_color(19, 0, calculateColorWithBrightness(22, brightness, 3), calculateColorWithBrightness(255, brightness, 3)); // 4
  rgb_matrix_set_color(20, 0, calculateColorWithBrightness(22, brightness, 3), calculateColorWithBrightness(255, brightness, 3)); // 5

  return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
