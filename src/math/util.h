#pragma once

/**
 * Converts degrees to radians.
 */
#define DEG_TO_RAD(deg)                                                        \
  do {                                                                         \
    (deg) * (M_PI / 180.0f)                                                    \
  } while (0)

/**
 * Converts radians to degrees.
 */
#define RAD_TO_DEG(rad)                                                        \
  do {                                                                         \
    (rad) * (180.0f / M_PI)                                                    \
  } while (0)