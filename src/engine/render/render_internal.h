#pragma once

#include <SDL2/SDL.h>

#include "../../types.h"

#include "render.h"

/**
 * Represents the internal state of the renderer.
 */
typedef struct render_state_internal {
  u32 vao_quad;
  u32 vbo_quad;
  u32 ebo_quad;
} RenderState_Internal;

/**
 * Initializes the renderer.
 */
SDL_Window *render_init_window(u32 width, u32 height);

/**
 * Initializes the quad for rendering.
 * @param vao The vertex array object.
 * @param vbo The vertex buffer object.
 * @param ebo The element buffer object.
 */
void render_init_quad(u32 *vao, u32 *vbo, u32 *ebo);