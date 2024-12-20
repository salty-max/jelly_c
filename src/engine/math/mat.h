#pragma once

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
 * Creates a simple projection matrix.
 *
 * @param width  Width of the projection.
 * @param height Height of the projection.
 * @param near   Near clipping plane.
 * @param far    Far clipping plane.
 * @return A Mat4 representing the projection.
 */
Mat4 mat4_projection(float width, float height, float near, float far);

/**
 * Creates a translation matrix.
 *
 * @param x Translation along the X-axis.
 * @param y Translation along the Y-axis.
 * @param z Translation along the Z-axis.
 * @return A Mat4 representing the translation.
 */
Mat4 mat4_translate(float x, float y, float z);

/**
 * Creates a rotation matrix for an arbitrary axis.
 *
 * @param angle Angle of rotation in radians.
 * @param x     X component of the rotation axis.
 * @param y     Y component of the rotation axis.
 * @param z     Z component of the rotation axis.
 * @return A Mat4 representing the rotation.
 */
Mat4 mat4_rotate(float angle, float x, float y, float z);

/**
 * Creates a rotation matrix around the X-axis.
 *
 * @param angle Angle of rotation in radians.
 * @return A Mat4 representing the X-axis rotation.
 */
Mat4 mat4_rotate_x(float angle);

/**
 * Creates a rotation matrix around the Y-axis.
 *
 * @param angle Angle of rotation in radians.
 * @return A Mat4 representing the Y-axis rotation.
 */
Mat4 mat4_rotate_y(float angle);

/**
 * Creates a rotation matrix around the Z-axis.
 *
 * @param angle Angle of rotation in radians.
 * @return A Mat4 representing the Z-axis rotation.
 */
Mat4 mat4_rotate_z(float angle);

/**
 * Creates a scaling matrix.
 *
 * @param x Scaling factor along the X-axis.
 * @param y Scaling factor along the Y-axis.
 * @param z Scaling factor along the Z-axis.
 * @return A Mat4 representing the scaling transformation.
 */
Mat4 mat4_scale(float x, float y, float z);

/**
 * Creates a scaling matrix for the X-axis.
 *
 * @param x Scaling factor along the X-axis.
 * @return A Mat4 representing the X-axis scaling.
 */
Mat4 mat4_scale_x(float x);

/**
 * Creates a scaling matrix for the Y-axis.
 *
 * @param y Scaling factor along the Y-axis.
 * @return A Mat4 representing the Y-axis scaling.
 */
Mat4 mat4_scale_y(float y);

/**
 * Creates a scaling matrix for the Z-axis.
 *
 * @param z Scaling factor along the Z-axis.
 * @return A Mat4 representing the Z-axis scaling.
 */
Mat4 mat4_scale_z(float z);

/**
 * Multiplies two 4x4 matrices.
 *
 * @param a First matrix.
 * @param b Second matrix.
 * @return The product of the two matrices.
 */
Mat4 mat4_mul(Mat4 a, Mat4 b);
