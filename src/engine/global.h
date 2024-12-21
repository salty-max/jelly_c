#pragma once

#include "render.h"
#include "config.h"
#include "input.h"
#include "time.h"

/**
 * Represents the global state of the engine.
 */
typedef struct global {
  RenderState render;
  ConfigState config;
  InputState input;
  TimeState time;
} Global;

extern Global global;