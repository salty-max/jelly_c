#pragma once

#include <stdbool.h>

/**
 * Represents a 4x4 matrix used for transformations in 3D graphics.
 * Elements are stored in a 2D array format.
 */
typedef struct mat4 {
  float m[4][4];
} Mat4;

/**
 * Generates a 4x4 identity matrix.
 * Useful as the starting point for transformations.
 *
 * @return A Mat4 initialized as an identity matrix.
 */
Mat4 mat4_identity();

/**
 * Creates an orthographic projection matrix.
 *
 * @param left   Left boundary of the view volume.
 * @param right  Right boundary of the view volume.
 * @param bottom Bottom boundary of the view volume.
 * @param top    Top boundary of the view volume.
 * @param near   Near clipping plane.
 * @param far    Far clipping plane.
 * @return A Mat4 representing the orthographic projection.
 */
Mat4 mat4_ortho(float left, float right, float bottom, float top, float near,
                float far);

/**
 * Creates a perspective projection matrix.
 *
 * @param fov    Field of view in radians.
 * @param aspect Aspect ratio of the view (width / height).
 * @param near   Near clipping plane.
 * @param far    Far clipping plane.
 * @return A Mat4 representing the perspective projection.
 */
Mat4 mat4_perspective(float fov, float aspect, float near, float far);

/**
 * Creates a projection matrix for simple 2D or 3D projections.
 *
 * @param width  Width of the projection.
 * @param height Height of the projection.
 * @param near   Near clipping plane.
 * @param far    Far clipping plane.
 * @return A Mat4 representing the projection.
 */
Mat4 mat4_projection(float width, float height, float near, float far);

/**
 * Modifies an existing matrix to apply a translation transformation.
 *
 * @param mat Pointer to the matrix to modify.
 * @param x   Translation along the X-axis.
 * @param y   Translation along the Y-axis.
 * @param z   Translation along the Z-axis.
 */
void mat4_translate(Mat4 *mat, float x, float y, float z);

/**
 * Creates a translation matrix.
 *
 * @param x Translation along the X-axis.
 * @param y Translation along the Y-axis.
 * @param z Translation along the Z-axis.
 * @return A Mat4 representing the translation transformation.
 */
Mat4 mat4_translation(float x, float y, float z);

/**
 * Modifies an existing matrix to apply a rotation around an arbitrary axis.
 *
 * @param mat   Pointer to the matrix to modify.
 * @param angle Angle of rotation in radians.
 * @param x     X component of the rotation axis.
 * @param y     Y component of the rotation axis.
 * @param z     Z component of the rotation axis.
 */
void mat4_rotate(Mat4 *mat, float angle, float x, float y, float z);

/**
 * Creates a rotation matrix for an arbitrary axis.
 *
 * @param angle Angle of rotation in radians.
 * @param x     X component of the rotation axis.
 * @param y     Y component of the rotation axis.
 * @param z     Z component of the rotation axis.
 * @return A Mat4 representing the rotation transformation.
 */
Mat4 mat4_rotation(float angle, float x, float y, float z);

/**
 * Creates a rotation matrix around the X-axis.
 *
 * @param angle Angle of rotation in radians.
 * @return A Mat4 representing the X-axis rotation.
 */
Mat4 mat4_rotation_x(float angle);

/**
 * Creates a rotation matrix around the Y-axis.
 *
 * @param angle Angle of rotation in radians.
 * @return A Mat4 representing the Y-axis rotation.
 */
Mat4 mat4_rotation_y(float angle);

/**
 * Creates a rotation matrix around the Z-axis.
 *
 * @param angle Angle of rotation in radians.
 * @return A Mat4 representing the Z-axis rotation.
 */
Mat4 mat4_rotation_z(float angle);

/**
 * Modifies an existing matrix to apply a scaling transformation.
 *
 * @param mat Pointer to the matrix to modify.
 * @param x   Scaling factor along the X-axis.
 * @param y   Scaling factor along the Y-axis.
 * @param z   Scaling factor along the Z-axis.
 */
void mat4_scale(Mat4 *mat, float x, float y, float z);

/**
 * Modifies an exisiting matrix to apply an anisotropic scaling transformation.
 *
 * @param mat Pointer to the matrix to modify.
 * @param x   Scaling factor along the X-axis.
 * @param y   Scaling factor along the Y-axis.
 * @param z   Scaling factor along the Z-axis.
 */
void mat4_scale_aniso(Mat4 *mat, float x, float y, float z);

/**
 * Creates a scaling matrix.
 *
 * @param x Scaling factor along the X-axis.
 * @param y Scaling factor along the Y-axis.
 * @param z Scaling factor along the Z-axis.
 * @return A Mat4 representing the scaling transformation.
 */
Mat4 mat4_scaling(float x, float y, float z);

/**
 * Multiplies two 4x4 matrices.
 *
 * @param result Pointer to the matrix where the result will be stored.
 * @param a      Pointer to the first matrix.
 * @param b      Pointer to the second matrix.
 */
void mat4_mul(Mat4 *result, const Mat4 *a, const Mat4 *b);

/**
 * Computes the determinant of a 4x4 matrix.
 *
 * @param mat Pointer to the matrix.
 * @return The determinant of the matrix.
 */
float mat4_determinant(const Mat4 *mat);

/**
 * Computes the inverse of a 4x4 matrix.
 *
 * @param result Pointer to the matrix where the inverse will be stored.
 * @param mat    Pointer to the matrix to invert.
 * @return True if the matrix is invertible; false otherwise.
 */
bool mat4_inverse(Mat4 *result, const Mat4 *mat);
