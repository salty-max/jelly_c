#pragma once

#include <SDL2/SDL.h>

#include "vec.h"
#include "mat.h"
#include "types.h"

/**
 * Represents the state of the renderer.
 */
typedef struct render_state {
  SDL_Window *window;
  f32 width;
  f32 height;
} RenderState;

/**
 * Initializes the renderer.
 */
void render_init(void);

/**
 * Begins rendering a frame.
 */
void render_begin(void);

/**
 * Ends rendering a frame.
 */
void render_end(void);

/**
 * Shuts down the renderer.
 */
void render_shutdown(void);

/**
 * Renders a quad.
 *
 * @param position The position of the quad.
 * @param size The size of the quad.
 * @param color The color of the quad.
 */
void render_quad(Vec2 position, Vec2 size, Vec4 color);