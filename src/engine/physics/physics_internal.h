#pragma once

#include "../array_list.h"
#include "../types.h"

typedef struct physics_state_internal {
  ArrayList *bodies;
} PhysicsState_Internal;