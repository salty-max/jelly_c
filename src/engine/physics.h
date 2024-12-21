#pragma once

#include "types.h"
#include "vec.h"

typedef struct aabb {
  Vec2 position;
  Vec2 half_size;
} AABB;

typedef struct body {
  AABB aabb;
  Vec2 velocity;
  Vec2 acceleration;
} Body;

void physics_init(void);
void physics_update(void);
usize physics_body_create(Vec2 position, Vec2 size);
Body *physics_body_get(usize index);
