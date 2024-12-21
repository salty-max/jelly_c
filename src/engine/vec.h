#pragma once

/**
 * Represents a 2D vector with float components.
 */
typedef struct vec2 {
  float x;
  float y;
} Vec2;

/**
 * Represents a 3D vector with float components.
 */
typedef struct vec3 {
  float x;
  float y;
  float z;
} Vec3;

/**
 * Represents a 4D vector with float components.
 */
typedef struct vec4 {
  float x;
  float y;
  float z;
  float w;
} Vec4;

/**
 * Creates a 2D vector with specified x and y components.
 */
Vec2 vec2(float x, float y);

/**
 * Creates a 3D vector with specified x, y, and z components.
 */
Vec3 vec3(float x, float y, float z);

/**
 * Creates a 4D vector with specified x, y, z, and w components.
 */
Vec4 vec4(float x, float y, float z, float w);

/**
 * Returns a 2D vector initialized to (0, 0).
 */
Vec2 vec2_zero();

/**
 * Returns a 3D vector initialized to (0, 0, 0).
 */
Vec3 vec3_zero();

/**
 * Returns a 4D vector initialized to (0, 0, 0, 0).
 */
Vec4 vec4_zero();

/**
 * Returns a 2D vector initialized to (1, 1).
 */
Vec2 vec2_one();

/**
 * Returns a 3D vector initialized to (1, 1, 1).
 */
Vec3 vec3_one();

/**
 * Returns a 4D vector initialized to (1, 1, 1, 1).
 */
Vec4 vec4_one();

/**
 * Adds two 2D vectors component-wise.
 */
Vec2 vec2_add(Vec2 a, Vec2 b);

/**
 * Adds two 3D vectors component-wise.
 */
Vec3 vec3_add(Vec3 a, Vec3 b);

/**
 * Adds two 4D vectors component-wise.
 */
Vec4 vec4_add(Vec4 a, Vec4 b);

/**
 * Subtracts two 2D vectors component-wise.
 */
Vec2 vec2_sub(Vec2 a, Vec2 b);

/**
 * Subtracts two 3D vectors component-wise.
 */
Vec3 vec3_sub(Vec3 a, Vec3 b);

/**
 * Subtracts two 4D vectors component-wise.
 */
Vec4 vec4_sub(Vec4 a, Vec4 b);

/**
 * Multiplies two 2D vectors component-wise.
 */
Vec2 vec2_mul(Vec2 a, Vec2 b);

/**
 * Multiplies two 3D vectors component-wise.
 */
Vec3 vec3_mul(Vec3 a, Vec3 b);

/**
 * Multiplies two 4D vectors component-wise.
 */
Vec4 vec4_mul(Vec4 a, Vec4 b);

/**
 * Divides two 2D vectors component-wise.
 */
Vec2 vec2_div(Vec2 a, Vec2 b);

/**
 * Divides two 3D vectors component-wise.
 */
Vec3 vec3_div(Vec3 a, Vec3 b);

/**
 * Divides two 4D vectors component-wise.
 */
Vec4 vec4_div(Vec4 a, Vec4 b);

/**
 * Scales a 2D vector by a scalar value.
 */
Vec2 vec2_scale(Vec2 a, float s);

/**
 * Scales a 3D vector by a scalar value.
 */
Vec3 vec3_scale(Vec3 a, float s);

/**
 * Scales a 4D vector by a scalar value.
 */
Vec4 vec4_scale(Vec4 a, float s);

/**
 * Computes the dot product of two 2D vectors.
 */
float vec2_dot(Vec2 a, Vec2 b);

/**
 * Computes the dot product of two 3D vectors.
 */
float vec3_dot(Vec3 a, Vec3 b);

/**
 * Computes the dot product of two 4D vectors.
 */
float vec4_dot(Vec4 a, Vec4 b);

/**
 * Computes the cross product of two 3D vectors.
 */
Vec3 vec3_cross(Vec3 a, Vec3 b);

/**
 * Computes the length (magnitude) of a 2D vector.
 */
float vec2_len(Vec2 a);

/**
 * Computes the length (magnitude) of a 3D vector.
 */
float vec3_len(Vec3 a);

/**
 * Computes the length (magnitude) of a 4D vector.
 */
float vec4_len(Vec4 a);

/**
 * Normalizes a 2D vector to have a length of 1.
 */
Vec2 vec2_norm(Vec2 a);

/**
 * Normalizes a 3D vector to have a length of 1.
 */
Vec3 vec3_norm(Vec3 a);

/**
 * Normalizes a 4D vector to have a length of 1.
 */
Vec4 vec4_norm(Vec4 a);

/**
 * Linearly interpolates between two 2D vectors.
 *
 * @param a The start vector.
 * @param b The end vector.
 * @param t Interpolation factor (0.0 to 1.0).
 * @return The interpolated vector.
 */
Vec2 vec2_lerp(Vec2 a, Vec2 b, float t);

/**
 * Linearly interpolates between two 3D vectors.
 *
 * @param a The start vector.
 * @param b The end vector.
 * @param t Interpolation factor (0.0 to 1.0).
 * @return The interpolated vector.
 */
Vec3 vec3_lerp(Vec3 a, Vec3 b, float t);

/**
 * Linearly interpolates between two 4D vectors.
 *
 * @param a The start vector.
 * @param b The end vector.
 * @param t Interpolation factor (0.0 to 1.0).
 * @return The interpolated vector.
 */
Vec4 vec4_lerp(Vec4 a, Vec4 b, float t);
