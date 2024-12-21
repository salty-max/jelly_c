#include <stdbool.h>
#include <math.h>

#include "../engine/vec.h"

#include "test_common.h"

// Helper function to compare vectors for equality with a tolerance
bool assert_vec2_eq(Vec2 a, Vec2 b, float epsilon, const char *msg) {
  return ASSERT_FLOAT_EQ(a.x, b.x, epsilon, msg) &
         ASSERT_FLOAT_EQ(a.y, b.y, epsilon, msg);
}

bool assert_vec3_eq(Vec3 a, Vec3 b, float epsilon, const char *msg) {
  return ASSERT_FLOAT_EQ(a.x, b.x, epsilon, msg) &
         ASSERT_FLOAT_EQ(a.y, b.y, epsilon, msg) &
         ASSERT_FLOAT_EQ(a.z, b.z, epsilon, msg);
}

bool assert_vec4_eq(Vec4 a, Vec4 b, float epsilon, const char *msg) {
  return ASSERT_FLOAT_EQ(a.x, b.x, epsilon, msg) &
         ASSERT_FLOAT_EQ(a.y, b.y, epsilon, msg) &
         ASSERT_FLOAT_EQ(a.z, b.z, epsilon, msg) &
         ASSERT_FLOAT_EQ(a.w, b.w, epsilon, msg);
}

bool test_vec2_operations() {
  printf(COLOR_YELLOW "Running test: vec2_operations...\n" COLOR_RESET);
  bool passed = true;

  Vec2 a = vec2(1.0f, 2.0f);
  Vec2 b = vec2(3.0f, 4.0f);

  // Addition
  passed &=
      assert_vec2_eq(vec2_add(a, b), vec2(4.0f, 6.0f), 1e-6, "vec2_add failed");

  // Subtraction
  passed &=
      assert_vec2_eq(vec2_sub(b, a), vec2(2.0f, 2.0f), 1e-6, "vec2_sub failed");

  // Multiplication
  passed &=
      assert_vec2_eq(vec2_mul(a, b), vec2(3.0f, 8.0f), 1e-6, "vec2_mul failed");

  // Division
  passed &=
      assert_vec2_eq(vec2_div(b, a), vec2(3.0f, 2.0f), 1e-6, "vec2_div failed");

  // Scaling
  passed &= assert_vec2_eq(vec2_scale(a, 2.0f), vec2(2.0f, 4.0f), 1e-6,
                           "vec2_scale failed");

  // Dot product
  passed &= ASSERT_FLOAT_EQ(vec2_dot(a, b), 11.0f, 1e-6, "vec2_dot failed");

  // Length
  passed &= ASSERT_FLOAT_EQ(vec2_len(vec2(3.0f, 4.0f)), 5.0f, 1e-6,
                            "vec2_len failed");

  // Normalize
  passed &= assert_vec2_eq(vec2_norm(vec2(3.0f, 4.0f)), vec2(0.6f, 0.8f), 1e-6,
                           "vec2_norm failed");

  // Lerp
  passed &= assert_vec2_eq(vec2_lerp(a, b, 0.5f), vec2(2.0f, 3.0f), 1e-6,
                           "vec2_lerp failed");

  if (passed) {
    printf(COLOR_GREEN "Test passed: vec2_operations\n" COLOR_RESET);
  }
  return passed;
}

bool test_vec3_operations() {
  printf(COLOR_YELLOW "Running test: vec3_operations...\n" COLOR_RESET);
  bool passed = true;

  Vec3 a = vec3(1.0f, 2.0f, 3.0f);
  Vec3 b = vec3(4.0f, 5.0f, 6.0f);

  // Addition
  passed &= assert_vec3_eq(vec3_add(a, b), vec3(5.0f, 7.0f, 9.0f), 1e-6,
                           "vec3_add failed");

  // Subtraction
  passed &= assert_vec3_eq(vec3_sub(b, a), vec3(3.0f, 3.0f, 3.0f), 1e-6,
                           "vec3_sub failed");

  // Multiplication
  passed &= assert_vec3_eq(vec3_mul(a, b), vec3(4.0f, 10.0f, 18.0f), 1e-6,
                           "vec3_mul failed");

  // Division
  passed &= assert_vec3_eq(vec3_div(b, a), vec3(4.0f, 2.5f, 2.0f), 1e-6,
                           "vec3_div failed");

  // Scaling
  passed &= assert_vec3_eq(vec3_scale(a, 2.0f), vec3(2.0f, 4.0f, 6.0f), 1e-6,
                           "vec3_scale failed");

  // Dot product
  passed &= ASSERT_FLOAT_EQ(vec3_dot(a, b), 32.0f, 1e-6, "vec3_dot failed");

  // Cross product
  passed &= assert_vec3_eq(vec3_cross(a, b), vec3(-3.0f, 6.0f, -3.0f), 1e-6,
                           "vec3_cross failed");

  // Length
  passed &= ASSERT_FLOAT_EQ(vec3_len(vec3(1.0f, 2.0f, 2.0f)), 3.0f, 1e-6,
                            "vec3_len failed");

  // Normalize
  Vec3 norm = vec3_norm(vec3(0.0f, 3.0f, 4.0f));
  passed &=
      assert_vec3_eq(norm, vec3(0.0f, 0.6f, 0.8f), 1e-6, "vec3_norm failed");

  // Lerp
  passed &= assert_vec3_eq(vec3_lerp(a, b, 0.5f), vec3(2.5f, 3.5f, 4.5f), 1e-6,
                           "vec3_lerp failed");

  if (passed) {
    printf(COLOR_GREEN "Test passed: vec3_operations\n" COLOR_RESET);
  }
  return passed;
}

bool test_vec4_operations() {
  printf(COLOR_YELLOW "Running test: vec4_operations...\n" COLOR_RESET);
  bool passed = true;

  Vec4 a = vec4(1.0f, 2.0f, 3.0f, 4.0f);
  Vec4 b = vec4(5.0f, 6.0f, 7.0f, 8.0f);

  // Addition
  passed &= assert_vec4_eq(vec4_add(a, b), vec4(6.0f, 8.0f, 10.0f, 12.0f), 1e-6,
                           "vec4_add failed");

  // Subtraction
  passed &= assert_vec4_eq(vec4_sub(b, a), vec4(4.0f, 4.0f, 4.0f, 4.0f), 1e-6,
                           "vec4_sub failed");

  // Multiplication
  passed &= assert_vec4_eq(vec4_mul(a, b), vec4(5.0f, 12.0f, 21.0f, 32.0f),
                           1e-6, "vec4_mul failed");

  // Division
  passed &= assert_vec4_eq(vec4_div(b, a), vec4(5.0f, 3.0f, 7.0f / 3.0f, 2.0f),
                           1e-6, "vec4_div failed");

  // Scaling
  passed &= assert_vec4_eq(vec4_scale(a, 2.0f), vec4(2.0f, 4.0f, 6.0f, 8.0f),
                           1e-6, "vec4_scale failed");

  // Dot product
  passed &= ASSERT_FLOAT_EQ(vec4_dot(a, b), 70.0f, 1e-6, "vec4_dot failed");

  // Length
  passed &= ASSERT_FLOAT_EQ(vec4_len(vec4(2.0f, 2.0f, 1.0f, 1.0f)),
                            sqrtf(10.0f), 1e-6, "vec4_len failed");

  // Normalize
  Vec4 norm = vec4_norm(vec4(0.0f, 4.0f, 3.0f, 0.0f));
  passed &= assert_vec4_eq(norm, vec4(0.0f, 0.8f, 0.6f, 0.0f), 1e-6,
                           "vec4_norm failed");

  // Lerp
  passed &= assert_vec4_eq(vec4_lerp(a, b, 0.5f), vec4(3.0f, 4.0f, 5.0f, 6.0f),
                           1e-6, "vec4_lerp failed");

  if (passed) {
    printf(COLOR_GREEN "Test passed: vec4_operations\n" COLOR_RESET);
  }
  return passed;
}

int main() {
  printf(COLOR_YELLOW "Starting vec.c tests...\n" COLOR_RESET);

  bool all_tests_passed = true;
  all_tests_passed &= test_vec2_operations();
  all_tests_passed &= test_vec3_operations();
  all_tests_passed &= test_vec4_operations();

  if (all_tests_passed) {
    printf(COLOR_GREEN "All vec.c tests passed!\n" COLOR_RESET);
  } else {
    fprintf(stderr, COLOR_RED "Some vec.c tests failed.\n" COLOR_RESET);
  }

  return all_tests_passed ? 0 : 1;
}
