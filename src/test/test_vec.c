#include <math.h>
#include <stdbool.h>

#include "../math/vec.h"
#include "test_common.h"

bool test_vec2_add() {
  printf(COLOR_YELLOW "Running test: vec2_add...\n" COLOR_RESET);
  bool passed = true;
  Vec2 a = vec2(1.0f, 2.0f);
  Vec2 b = vec2(3.0f, 4.0f);
  Vec2 result = vec2_add(a, b);
  passed &= ASSERT_FLOAT_EQ(result.x, 4.0f, 1e-6, "vec2_add: x should be 4");
  passed &= ASSERT_FLOAT_EQ(result.y, 6.0f, 1e-6, "vec2_add: y should be 6");
  if (passed) {
    printf(COLOR_GREEN "Test passed: vec2_add\n" COLOR_RESET);
  }
  return passed;
}

bool test_vec2_length() {
  printf(COLOR_YELLOW "Running test: vec2_length...\n" COLOR_RESET);
  bool passed = true;
  Vec2 a = vec2(3.0f, 4.0f);
  float length = vec2_len(a);
  passed &= ASSERT_FLOAT_EQ(length, 5.0f, 1e-6, "vec2_len: length should be 5");
  if (passed) {
    printf(COLOR_GREEN "Test passed: vec2_length\n" COLOR_RESET);
  }
  return passed;
}

int main() {
  printf(COLOR_YELLOW "Starting vec.c tests...\n" COLOR_RESET);

  bool all_tests_passed = true;

  all_tests_passed &= test_vec2_add();
  all_tests_passed &= test_vec2_length();

  if (all_tests_passed) {
    printf(COLOR_GREEN "All vec.c tests passed!\n" COLOR_RESET);
  } else {
    fprintf(stderr, COLOR_RED "Some vec.c tests failed.\n" COLOR_RESET);
  }

  return all_tests_passed ? 0 : 1;
}
