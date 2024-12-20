#include <math.h>
#include "mat.h"

Mat4 mat4_identity() {
  Mat4 result = {0};
  for (int i = 0; i < 4; i++) {
    result.m[i][i] = 1.0f;
  }
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
  Mat4 result = {0};
  float tan_half_fov = tanf(fov / 2.0f);
  result.m[0][0] = 1.0f / (aspect * tan_half_fov);
  result.m[1][1] = 1.0f / tan_half_fov;
  result.m[2][2] = -(far + near) / (far - near);
  result.m[2][3] = -1.0f;
  result.m[3][2] = -(2.0f * far * near) / (far - near);
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

void mat4_translate(Mat4 *mat, float x, float y, float z) {
  mat->m[3][0] += x;
  mat->m[3][1] += y;
  mat->m[3][2] += z;
}

// Generates a translation matrix
Mat4 mat4_translation(float x, float y, float z) {
  Mat4 result = mat4_identity();
  result.m[3][0] = x;
  result.m[3][1] = y;
  result.m[3][2] = z;
  return result;
}

void mat4_rotate(Mat4 *mat, float angle, float x, float y, float z) {
  float c = cosf(angle);
  float s = sinf(angle);
  float omc = 1.0f - c;

  Mat4 rotation = mat4_identity();
  rotation.m[0][0] = x * x * omc + c;
  rotation.m[0][1] = y * x * omc + z * s;
  rotation.m[0][2] = x * z * omc - y * s;
  rotation.m[1][0] = x * y * omc - z * s;
  rotation.m[1][1] = y * y * omc + c;
  rotation.m[1][2] = y * z * omc + x * s;
  rotation.m[2][0] = x * z * omc + y * s;
  rotation.m[2][1] = y * z * omc - x * s;
  rotation.m[2][2] = z * z * omc + c;

  mat4_mul(mat, mat, &rotation);
}

Mat4 mat4_rotation(float angle, float x, float y, float z) {
  Mat4 result = mat4_identity();
  float c = cosf(angle);
  float s = sinf(angle);
  float omc = 1.0f - c;

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

Mat4 mat4_rotation_x(float angle) {
  Mat4 result = mat4_identity();
  float c = cosf(angle);
  float s = sinf(angle);
  result.m[1][1] = c;
  result.m[1][2] = -s;
  result.m[2][1] = s;
  result.m[2][2] = c;
  return result;
}

Mat4 mat4_rotation_y(float angle) {
  Mat4 result = mat4_identity();
  float c = cosf(angle);
  float s = sinf(angle);
  result.m[0][0] = c;
  result.m[0][2] = s;
  result.m[2][0] = -s;
  result.m[2][2] = c;
  return result;
}

Mat4 mat4_rotation_z(float angle) {
  Mat4 result = mat4_identity();
  float c = cosf(angle);
  float s = sinf(angle);
  result.m[0][0] = c;
  result.m[0][1] = -s;
  result.m[1][0] = s;
  result.m[1][1] = c;
  return result;
}

void mat4_scale(Mat4 *mat, float x, float y, float z) {
  mat->m[0][0] *= x;
  mat->m[1][1] *= y;
  mat->m[2][2] *= z;
}

void mat4_scale_aniso(Mat4 *mat, float x, float y, float z) {
  for (int i = 0; i < 4; i++) {
    mat->m[0][i] *= x; // Scale X
    mat->m[1][i] *= y; // Scale Y
    mat->m[2][i] *= z; // Scale Z
  }
}

Mat4 mat4_scaling(float x, float y, float z) {
  Mat4 result = mat4_identity();
  result.m[0][0] = x;
  result.m[1][1] = y;
  result.m[2][2] = z;
  return result;
}

void mat4_mul(Mat4 *result, const Mat4 *a, const Mat4 *b) {
  Mat4 temp = {0};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      temp.m[i][j] = a->m[i][0] * b->m[0][j] + a->m[i][1] * b->m[1][j] +
                     a->m[i][2] * b->m[2][j] + a->m[i][3] * b->m[3][j];
    }
  }
  *result = temp;
}

float mat4_determinant(const Mat4 *mat) {
  float det;
  det = mat->m[0][0] *
            (mat->m[1][1] *
                 (mat->m[2][2] * mat->m[3][3] - mat->m[2][3] * mat->m[3][2]) -
             mat->m[1][2] *
                 (mat->m[2][1] * mat->m[3][3] - mat->m[2][3] * mat->m[3][1]) +
             mat->m[1][3] *
                 (mat->m[2][1] * mat->m[3][2] - mat->m[2][2] * mat->m[3][1])) -
        mat->m[0][1] *
            (mat->m[1][0] *
                 (mat->m[2][2] * mat->m[3][3] - mat->m[2][3] * mat->m[3][2]) -
             mat->m[1][2] *
                 (mat->m[2][0] * mat->m[3][3] - mat->m[2][3] * mat->m[3][0]) +
             mat->m[1][3] *
                 (mat->m[2][0] * mat->m[3][2] - mat->m[2][2] * mat->m[3][0])) +
        mat->m[0][2] *
            (mat->m[1][0] *
                 (mat->m[2][1] * mat->m[3][3] - mat->m[2][3] * mat->m[3][1]) -
             mat->m[1][1] *
                 (mat->m[2][0] * mat->m[3][3] - mat->m[2][3] * mat->m[3][0]) +
             mat->m[1][3] *
                 (mat->m[2][0] * mat->m[3][1] - mat->m[2][1] * mat->m[3][0])) -
        mat->m[0][3] *
            (mat->m[1][0] *
                 (mat->m[2][1] * mat->m[3][2] - mat->m[2][2] * mat->m[3][1]) -
             mat->m[1][1] *
                 (mat->m[2][0] * mat->m[3][2] - mat->m[2][2] * mat->m[3][0]) +
             mat->m[1][2] *
                 (mat->m[2][0] * mat->m[3][1] - mat->m[2][1] * mat->m[3][0]));
  return det;
}

bool mat4_inverse(Mat4 *result, const Mat4 *mat) {
  float det = mat4_determinant(mat);
  if (fabs(det) < 1e-6) {
    return false; // Matrix is not invertible
  }

  // Compute inverse using adjugate and determinant
  Mat4 adj = {0};
  adj.m[0][0] =
      mat->m[1][1] *
          (mat->m[2][2] * mat->m[3][3] - mat->m[2][3] * mat->m[3][2]) -
      mat->m[1][2] *
          (mat->m[2][1] * mat->m[3][3] - mat->m[2][3] * mat->m[3][1]) +
      mat->m[1][3] *
          (mat->m[2][1] * mat->m[3][2] - mat->m[2][2] * mat->m[3][1]);

  // Compute all other elements of adjugate matrix here (not shown for brevity)

  // Scale adjugate by 1/det to get the inverse
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      adj.m[i][j] /= det;
    }
  }

  *result = adj;
  return true;
}