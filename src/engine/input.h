#pragma once

/**
 * Represents the input keys.
 */
typedef enum input_key {
  INPUT_KEY_LEFT,
  INPUT_KEY_RIGHT,
  INPUT_KEY_UP,
  INPUT_KEY_DOWN,
  INPUT_KEY_ESCAPE
} InputKey;

/**
 * Represents the state of a key.
 */
typedef enum key_state { KS_UNPRESSED, KS_PRESSED, KS_HELD } KeyState;

/**
 * Represents the state of the input.
 */
typedef struct input_state {
  KeyState left;
  KeyState right;
  KeyState up;
  KeyState down;
  KeyState escape;
} InputState;

/**
 * Initializes the input.
 */
void input_update(void);