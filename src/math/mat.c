#include <math.h>

#include "mat.h"

Mat4 mat4_identity() {
  Mat4 result;
  result.m[0][0] = 1.0f;
  result.m[0][1] = 0.0f;
  result.m[0][2] = 0.0f;
  result.m[0][3] = 0.0f;
  result.m[1][0] = 0.0f;
  result.m[1][1] = 1.0f;
  result.m[1][2] = 0.0f;
  result.m[1][3] = 0.0f;
  result.m[2][0] = 0.0f;
  result.m[2][1] = 0.0f;
  result.m[2][2] = 1.0f;
  result.m[2][3] = 0.0f;
  result.m[3][0] = 0.0f;
  result.m[3][1] = 0.0f;
  result.m[3][2] = 0.0f;
  result.m[3][3] = 1.0f;
  return result;
}

Mat4 mat4_ortho(float left, float right, float bottom, float top, float near,
                float far) {
  Mat4 result = mat4_identity();
  result.m[0][0] = 2.0f / (right - left);
  result.m[1][1] = 2.0f / (top - bottom);
  result.m[2][2] = -2.0f / (far - near);
  result.m[3][0] = -(right + left) / (right - left);
  result.m[3][1] = -(top + bottom) / (top - bottom);
  result.m[3][2] = -(far + near) / (far - near);
  return result;
}

Mat4 mat4_perspective(float fov, float aspect, float near, float far) {
  float tan_half_fov = tanf(fov / 2.0f);
  Mat4 result = mat4_identity();
  result.m[0][0] = 1.0f / (aspect * tan_half_fov);
  result.m[1][1] = 1.0f / tan_half_fov;
  result.m[2][2] = -(far + near) / (far - near);
  result.m[2][3] = -1.0f;
  result.m[3][2] = -(2.0f * far * near) / (far - near);
  result.m[3][3] = 0.0f;
  return result;
}

Mat4 mat4_projection(float width, float height, float near, float far) {
  Mat4 result = mat4_identity();
  result.m[0][0] = 2.0f / width;
  result.m[1][1] = 2.0f / height;
  result.m[2][2] = -2.0f / (far - near);
  result.m[3][2] = -(far + near) / (far - near);
  return result;
}

Mat4 mat4_translate(float x, float y, float z) {
  Mat4 result = mat4_identity();
  result.m[3][0] = x;
  result.m[3][1] = y;
  result.m[3][2] = z;
  return result;
}

Mat4 mat4_rotate(float angle, float x, float y, float z) {
  float c = cosf(angle);
  float s = sinf(angle);
  float omc = 1.0f - c;
  Mat4 result = mat4_identity();
  result.m[0][0] = x * x * omc + c;
  result.m[0][1] = y * x * omc + z * s;
  result.m[0][2] = x * z * omc - y * s;
  result.m[1][0] = x * y * omc - z * s;
  result.m[1][1] = y * y * omc + c;
  result.m[1][2] = y * z * omc + x * s;
  result.m[2][0] = x * z * omc + y * s;
  result.m[2][1] = y * z * omc - x * s;
  result.m[2][2] = z * z * omc + c;
  return result;
}

Mat4 mat4_rotate_x(float angle) {
  float c = cosf(angle);
  float s = sinf(angle);
  Mat4 result = mat4_identity();
  result.m[1][1] = c;
  result.m[1][2] = -s;
  result.m[2][1] = s;
  result.m[2][2] = c;
  return result;
}

Mat4 mat4_rotate_y(float angle) {
  float c = cosf(angle);
  float s = sinf(angle);
  Mat4 result = mat4_identity();
  result.m[0][0] = c;
  result.m[0][2] = s;
  result.m[2][0] = -s;
  result.m[2][2] = c;
  return result;
}

Mat4 mat4_rotate_z(float angle) {
  float c = cosf(angle);
  float s = sinf(angle);
  Mat4 result = mat4_identity();
  result.m[0][0] = c;
  result.m[0][1] = -s;
  result.m[1][0] = s;
  result.m[1][1] = c;
  return result;
}

Mat4 mat4_scale(float x, float y, float z) {
  Mat4 result = mat4_identity();
  result.m[0][0] = x;
  result.m[1][1] = y;
  result.m[2][2] = z;
  return result;
}

Mat4 mat4_scale_x(float x) {
  Mat4 result = mat4_identity();
  result.m[0][0] = x;
  return result;
}

Mat4 mat4_scale_y(float y) {
  Mat4 result = mat4_identity();
  result.m[1][1] = y;
  return result;
}

Mat4 mat4_scale_z(float z) {
  Mat4 result = mat4_identity();
  result.m[2][2] = z;
  return result;
}

Mat4 mat4_mul(Mat4 a, Mat4 b) {
  Mat4 result = mat4_identity();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      result.m[i][j] = a.m[i][0] * b.m[0][j] + a.m[i][1] * b.m[1][j] +
                       a.m[i][2] * b.m[2][j] + a.m[i][3] * b.m[3][j];
    }
  }
  return result;
}
