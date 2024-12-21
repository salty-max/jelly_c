#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../engine/util.h"

// ANSI color codes
#define COLOR_RESET "\033[0m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_RED "\033[0;31m"
#define COLOR_YELLOW "\033[0;33m"

// Macro to assert a condition and return a boolean value
#define ASSERT_TRUE(cond, msg)                                                 \
  ((cond) ? true                                                               \
          : (fprintf(stderr, COLOR_RED "ASSERTION FAILED: %s\n" COLOR_RESET,   \
                     msg),                                                     \
             false))

// Macro to compare floats with epsilon tolerance and return a boolean value
#define ASSERT_FLOAT_EQ(a, b, epsilon, msg)                                    \
  ((fabs((a) - (b)) <= epsilon)                                                \
       ? true                                                                  \
       : (fprintf(stderr, COLOR_RED "ASSERTION FAILED: %s\n" COLOR_RESET,      \
                  msg),                                                        \
          false))
