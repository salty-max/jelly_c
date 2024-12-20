#pragma once

#include "render/render.h"

/**
 * Represents the global state of the engine.
 */
typedef struct global {
  RenderState render;
} Global;

extern Global global;