#include <stdbool.h>
#include <math.h>

#include "../math/mat.h"
#include "test_common.h"

bool test_mat4_identity() {
  printf(COLOR_YELLOW "Running test: mat4_identity...\n" COLOR_RESET);
  bool passed = true;
  Mat4 identity = mat4_identity();
  passed &= ASSERT_FLOAT_EQ(identity.m[0][0], 1.0f, 1e-6,
                            "mat4_identity: m[0][0] should be 1");
  passed &= ASSERT_FLOAT_EQ(identity.m[1][1], 1.0f, 1e-6,
                            "mat4_identity: m[1][1] should be 1");
  passed &= ASSERT_FLOAT_EQ(identity.m[2][2], 1.0f, 1e-6,
                            "mat4_identity: m[2][2] should be 1");
  passed &= ASSERT_FLOAT_EQ(identity.m[3][3], 1.0f, 1e-6,
                            "mat4_identity: m[3][3] should be 1");
  if (passed) {
    printf(COLOR_GREEN "Test passed: mat4_identity\n" COLOR_RESET);
  }
  return passed;
}

bool test_mat4_translation() {
  printf(COLOR_YELLOW "Running test: mat4_translation...\n" COLOR_RESET);
  bool passed = true;
  Mat4 translation = mat4_translate(3.0f, 4.0f, 5.0f);
  passed &= ASSERT_FLOAT_EQ(translation.m[3][0], 3.0f, 1e-6,
                            "mat4_translate: m[3][0] should be 3");
  passed &= ASSERT_FLOAT_EQ(translation.m[3][1], 4.0f, 1e-6,
                            "mat4_translate: m[3][1] should be 4");
  passed &= ASSERT_FLOAT_EQ(translation.m[3][2], 5.0f, 1e-6,
                            "mat4_translate: m[3][2] should be 5");
  if (passed) {
    printf(COLOR_GREEN "Test passed: mat4_translation\n" COLOR_RESET);
  }
  return passed;
}

int main() {
  printf(COLOR_YELLOW "Starting mat.c tests...\n" COLOR_RESET);

  bool all_tests_passed = true;

  all_tests_passed &= test_mat4_identity();
  all_tests_passed &= test_mat4_translation();

  if (all_tests_passed) {
    printf(COLOR_GREEN "All mat.c tests passed!\n" COLOR_RESET);
  } else {
    fprintf(stderr, COLOR_RED "Some mat.c tests failed.\n" COLOR_RESET);
  }

  return all_tests_passed ? 0 : 1;
}
