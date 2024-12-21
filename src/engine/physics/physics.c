#include "../vec.h"
#include "../util.h"
#include "../global.h"
#include "../array_list.h"
#include "../physics.h"
#include "physics_internal.h"

static PhysicsState_Internal state;

void physics_init(void) { state.bodies = array_list_create(sizeof(Body), 10); }

void physics_update(void) {
  Body *body;

  for (u32 i = 0; i < state.bodies->len; ++i) {
    body = array_list_get(state.bodies, i);
    body->velocity.x += body->acceleration.x * global.time.delta;
    body->velocity.y += body->acceleration.y * global.time.delta;
    body->aabb.position.x += body->velocity.x * global.time.delta;
    body->aabb.position.y += body->velocity.y * global.time.delta;
  }
}

usize physics_body_create(Vec2 position, Vec2 size) {
  Body body = {
      .aabb = {.position = position, .half_size = vec2_scale(size, 0.5f)},
      .velocity = vec2_zero(),
      .acceleration = vec2_zero()};

  if (array_list_append(state.bodies, &body) == -1) {
    ERROR_RETURN(-1, "Could not append body to list\n");
  }

  return state.bodies->len - 1;
}

Body *physics_body_get(usize index) {
  return array_list_get(state.bodies, index);
}