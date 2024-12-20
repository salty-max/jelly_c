#include <stdbool.h>
#include <math.h>

#include "../math/mat.h"

#include "test_common.h"

#ifndef M_PI
#define M_PI acosf(-1.0f)
#endif

bool test_mat4_identity() {
  printf(COLOR_YELLOW "Running test: mat4_identity...\n" COLOR_RESET);
  bool passed = true;
  Mat4 identity = mat4_identity();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      float expected = (i == j) ? 1.0f : 0.0f;
      passed &= ASSERT_FLOAT_EQ(identity.m[i][j], expected, 1e-6,
                                "mat4_identity: Incorrect matrix element");
    }
  }
  if (passed) {
    printf(COLOR_GREEN "Test passed: mat4_identity\n" COLOR_RESET);
  }
  return passed;
}

bool test_mat4_ortho() {
  printf(COLOR_YELLOW "Running test: mat4_ortho...\n" COLOR_RESET);
  bool passed = true;
  Mat4 ortho = mat4_ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
  passed &= ASSERT_FLOAT_EQ(ortho.m[0][0], 1.0f, 1e-6,
                            "mat4_ortho: Incorrect m[0][0]");
  passed &= ASSERT_FLOAT_EQ(ortho.m[1][1], 1.0f, 1e-6,
                            "mat4_ortho: Incorrect m[1][1]");
  passed &= ASSERT_FLOAT_EQ(ortho.m[2][2], -1.0f, 1e-6,
                            "mat4_ortho: Incorrect m[2][2]");
  passed &= ASSERT_FLOAT_EQ(ortho.m[3][3], 1.0f, 1e-6,
                            "mat4_ortho: Incorrect m[3][3]");
  if (passed) {
    printf(COLOR_GREEN "Test passed: mat4_ortho\n" COLOR_RESET);
  }
  return passed;
}

bool test_mat4_perspective() {
  printf(COLOR_YELLOW "Running test: mat4_perspective...\n" COLOR_RESET);
  bool passed = true;
  Mat4 perspective = mat4_perspective(M_PI / 2.0f, 1.0f, 0.1f, 100.0f);
  passed &= ASSERT_FLOAT_EQ(perspective.m[0][0], 1.0f, 1e-6,
                            "mat4_perspective: Incorrect m[0][0]");
  passed &= ASSERT_FLOAT_EQ(perspective.m[1][1], 1.0f, 1e-6,
                            "mat4_perspective: Incorrect m[1][1]");
  passed &= ASSERT_FLOAT_EQ(perspective.m[2][2], -1.002002f, 1e-6,
                            "mat4_perspective: Incorrect m[2][2]");
  passed &= ASSERT_FLOAT_EQ(perspective.m[2][3], -1.0f, 1e-6,
                            "mat4_perspective: Incorrect m[2][3]");
  passed &= ASSERT_FLOAT_EQ(perspective.m[3][2], -0.2002f, 1e-6,
                            "mat4_perspective: Incorrect m[3][2]");
  if (passed) {
    printf(COLOR_GREEN "Test passed: mat4_perspective\n" COLOR_RESET);
  }
  return passed;
}

bool test_mat4_rotate_x() {
  printf(COLOR_YELLOW "Running test: mat4_rotate_x...\n" COLOR_RESET);
  bool passed = true;

  // Test rotation about the x-axis
  Mat4 rotation = mat4_rotate_x(M_PI / 4.0f);

  passed &= ASSERT_FLOAT_EQ(rotation.m[1][1], cosf(M_PI / 4.0f), 1e-6,
                            "mat4_rotate_x: Incorrect m[1][1]");
  passed &= ASSERT_FLOAT_EQ(rotation.m[1][2], -sinf(M_PI / 4.0f), 1e-6,
                            "mat4_rotate_x: Incorrect m[1][2]");
  passed &= ASSERT_FLOAT_EQ(rotation.m[2][1], sinf(M_PI / 4.0f), 1e-6,
                            "mat4_rotate_x: Incorrect m[2][1]");
  passed &= ASSERT_FLOAT_EQ(rotation.m[2][2], cosf(M_PI / 4.0f), 1e-6,
                            "mat4_rotate_x: Incorrect m[2][2]");
  passed &= ASSERT_FLOAT_EQ(
      rotation.m[0][0], 1.0f, 1e-6,
      "mat4_rotate_x: Incorrect m[0][0] (x-axis remains unchanged)");

  if (passed) {
    printf(COLOR_GREEN "Test passed: mat4_rotate_x\n" COLOR_RESET);
  }
  return passed;
}

bool test_mat4_rotate_y() {
  printf(COLOR_YELLOW "Running test: mat4_rotate_y...\n" COLOR_RESET);
  bool passed = true;

  // Test rotation about the y-axis
  Mat4 rotation = mat4_rotate_y(M_PI / 4.0f);

  passed &= ASSERT_FLOAT_EQ(rotation.m[0][0], cosf(M_PI / 4.0f), 1e-6,
                            "mat4_rotate_y: Incorrect m[0][0]");
  passed &= ASSERT_FLOAT_EQ(rotation.m[0][2], sinf(M_PI / 4.0f), 1e-6,
                            "mat4_rotate_y: Incorrect m[0][2]");
  passed &= ASSERT_FLOAT_EQ(rotation.m[2][0], -sinf(M_PI / 4.0f), 1e-6,
                            "mat4_rotate_y: Incorrect m[2][0]");
  passed &= ASSERT_FLOAT_EQ(rotation.m[2][2], cosf(M_PI / 4.0f), 1e-6,
                            "mat4_rotate_y: Incorrect m[2][2]");
  passed &= ASSERT_FLOAT_EQ(
      rotation.m[1][1], 1.0f, 1e-6,
      "mat4_rotate_y: Incorrect m[1][1] (y-axis remains unchanged)");

  if (passed) {
    printf(COLOR_GREEN "Test passed: mat4_rotate_y\n" COLOR_RESET);
  }
  return passed;
}

bool test_mat4_rotate_z() {
  printf(COLOR_YELLOW "Running test: mat4_rotate_z...\n" COLOR_RESET);
  bool passed = true;

  // Test rotation about the z-axis
  Mat4 rotation = mat4_rotate_z(M_PI / 4.0f);

  passed &= ASSERT_FLOAT_EQ(rotation.m[0][0], cosf(M_PI / 4.0f), 1e-6,
                            "mat4_rotate_z: Incorrect m[0][0]");
  passed &= ASSERT_FLOAT_EQ(rotation.m[0][1], -sinf(M_PI / 4.0f), 1e-6,
                            "mat4_rotate_z: Incorrect m[0][1]");
  passed &= ASSERT_FLOAT_EQ(rotation.m[1][0], sinf(M_PI / 4.0f), 1e-6,
                            "mat4_rotate_z: Incorrect m[1][0]");
  passed &= ASSERT_FLOAT_EQ(rotation.m[1][1], cosf(M_PI / 4.0f), 1e-6,
                            "mat4_rotate_z: Incorrect m[1][1]");
  passed &= ASSERT_FLOAT_EQ(
      rotation.m[2][2], 1.0f, 1e-6,
      "mat4_rotate_z: Incorrect m[2][2] (z-axis remains unchanged)");

  if (passed) {
    printf(COLOR_GREEN "Test passed: mat4_rotate_z\n" COLOR_RESET);
  }
  return passed;
}

bool test_mat4_translate() {
  printf(COLOR_YELLOW "Running test: mat4_translate...\n" COLOR_RESET);
  bool passed = true;
  Mat4 translation = mat4_translate(3.0f, 4.0f, 5.0f);
  passed &= ASSERT_FLOAT_EQ(translation.m[3][0], 3.0f, 1e-6,
                            "mat4_translate: Incorrect x translation");
  passed &= ASSERT_FLOAT_EQ(translation.m[3][1], 4.0f, 1e-6,
                            "mat4_translate: Incorrect y translation");
  passed &= ASSERT_FLOAT_EQ(translation.m[3][2], 5.0f, 1e-6,
                            "mat4_translate: Incorrect z translation");
  if (passed) {
    printf(COLOR_GREEN "Test passed: mat4_translate\n" COLOR_RESET);
  }
  return passed;
}

bool test_mat4_scale() {
  printf(COLOR_YELLOW "Running test: mat4_scale...\n" COLOR_RESET);
  bool passed = true;
  Mat4 scale = mat4_scale(2.0f, 3.0f, 4.0f);
  passed &= ASSERT_FLOAT_EQ(scale.m[0][0], 2.0f, 1e-6,
                            "mat4_scale: Incorrect x scale");
  passed &= ASSERT_FLOAT_EQ(scale.m[1][1], 3.0f, 1e-6,
                            "mat4_scale: Incorrect y scale");
  passed &= ASSERT_FLOAT_EQ(scale.m[2][2], 4.0f, 1e-6,
                            "mat4_scale: Incorrect z scale");
  if (passed) {
    printf(COLOR_GREEN "Test passed: mat4_scale\n" COLOR_RESET);
  }
  return passed;
}

bool test_mat4_mul() {
  printf(COLOR_YELLOW "Running test: mat4_mul...\n" COLOR_RESET);
  bool passed = true;
  Mat4 a = mat4_identity();
  Mat4 b = mat4_translate(1.0f, 2.0f, 3.0f);
  Mat4 result = mat4_mul(a, b);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      passed &=
          ASSERT_FLOAT_EQ(result.m[i][j], b.m[i][j], 1e-6,
                          "mat4_mul: Incorrect matrix multiplication result");
    }
  }
  if (passed) {
    printf(COLOR_GREEN "Test passed: mat4_mul\n" COLOR_RESET);
  }
  return passed;
}

int main() {
  printf(COLOR_YELLOW "Starting mat.c tests...\n" COLOR_RESET);

  bool all_tests_passed = true;
  all_tests_passed &= test_mat4_identity();
  all_tests_passed &= test_mat4_ortho();
  all_tests_passed &= test_mat4_perspective();
  all_tests_passed &= test_mat4_rotate_x();
  all_tests_passed &= test_mat4_rotate_y();
  all_tests_passed &= test_mat4_rotate_z();
  all_tests_passed &= test_mat4_translate();
  all_tests_passed &= test_mat4_scale();
  all_tests_passed &= test_mat4_mul();

  if (all_tests_passed) {
    printf(COLOR_GREEN "All mat.c tests passed!\n" COLOR_RESET);
  } else {
    fprintf_s(stderr, COLOR_RED "Some mat.c tests failed.\n" COLOR_RESET);
  }

  return all_tests_passed ? 0 : 1;
}
