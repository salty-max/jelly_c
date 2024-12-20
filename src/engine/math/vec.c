#include <math.h>

#include "vec.h"

Vec2 vec2(float x, float y) { return (Vec2){x, y}; }

Vec3 vec3(float x, float y, float z) { return (Vec3){x, y, z}; }

Vec4 vec4(float x, float y, float z, float w) { return (Vec4){x, y, z, w}; }

Vec2 vec2_zero() { return vec2(0, 0); }

Vec3 vec3_zero() { return vec3(0, 0, 0); }

Vec4 vec4_zero() { return vec4(0, 0, 0, 0); }

Vec2 vec2_one() { return vec2(1, 1); }

Vec3 vec3_one() { return vec3(1, 1, 1); }

Vec4 vec4_one() { return vec4(1, 1, 1, 1); }

Vec2 vec2_add(Vec2 a, Vec2 b) { return vec2(a.x + b.x, a.y + b.y); }

Vec3 vec3_add(Vec3 a, Vec3 b) { return vec3(a.x + b.x, a.y + b.y, a.z + b.z); }

Vec4 vec4_add(Vec4 a, Vec4 b) {
  return vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

Vec2 vec2_sub(Vec2 a, Vec2 b) { return vec2(a.x - b.x, a.y - b.y); }

Vec3 vec3_sub(Vec3 a, Vec3 b) { return vec3(a.x - b.x, a.y - b.y, a.z - b.z); }

Vec4 vec4_sub(Vec4 a, Vec4 b) {
  return vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

Vec2 vec2_mul(Vec2 a, Vec2 b) { return vec2(a.x * b.x, a.y * b.y); }

Vec3 vec3_mul(Vec3 a, Vec3 b) { return vec3(a.x * b.x, a.y * b.y, a.z * b.z); }

Vec4 vec4_mul(Vec4 a, Vec4 b) {
  return vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}

Vec2 vec2_div(Vec2 a, Vec2 b) { return vec2(a.x / b.x, a.y / b.y); }

Vec3 vec3_div(Vec3 a, Vec3 b) { return vec3(a.x / b.x, a.y / b.y, a.z / b.z); }

Vec4 vec4_div(Vec4 a, Vec4 b) {
  return vec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
}

Vec2 vec2_scale(Vec2 a, float s) { return vec2(a.x * s, a.y * s); }

Vec3 vec3_scale(Vec3 a, float s) { return vec3(a.x * s, a.y * s, a.z * s); }

Vec4 vec4_scale(Vec4 a, float s) {
  return vec4(a.x * s, a.y * s, a.z * s, a.w * s);
}

float vec2_dot(Vec2 a, Vec2 b) { return a.x * b.x + a.y * b.y; }

float vec3_dot(Vec3 a, Vec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

float vec4_dot(Vec4 a, Vec4 b) {
  return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

Vec3 vec3_cross(Vec3 a, Vec3 b) {
  return vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
              a.x * b.y - a.y * b.x);
}

float vec2_len(Vec2 a) { return sqrtf(vec2_dot(a, a)); }

float vec3_len(Vec3 a) { return sqrtf(vec3_dot(a, a)); }

float vec4_len(Vec4 a) { return sqrtf(vec4_dot(a, a)); }

Vec2 vec2_norm(Vec2 a) { return vec2_scale(a, 1.0f / vec2_len(a)); }

Vec3 vec3_norm(Vec3 a) { return vec3_scale(a, 1.0f / vec3_len(a)); }

Vec4 vec4_norm(Vec4 a) { return vec4_scale(a, 1.0f / vec4_len(a)); }

Vec2 vec2_lerp(Vec2 a, Vec2 b, float t) {
  return vec2_add(vec2_scale(a, 1.0f - t), vec2_scale(b, t));
}

Vec3 vec3_lerp(Vec3 a, Vec3 b, float t) {
  return vec3_add(vec3_scale(a, 1.0f - t), vec3_scale(b, t));
}

Vec4 vec4_lerp(Vec4 a, Vec4 b, float t) {
  return vec4_add(vec4_scale(a, 1.0f - t), vec4_scale(b, t));
}