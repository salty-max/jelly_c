#pragma once

#include <SDL2/SDL.h>

#include "../types.h"
#include "../mat.h"
#include "../render.h"

/**
 * Represents the internal state of the renderer.
 */
typedef struct render_state_internal {
  u32 vao_quad;
  u32 vbo_quad;
  u32 ebo_quad;
  u32 shader_default;
  u32 texture_color;
  Mat4 projection;
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

/**
 * Initializes the color texture.
 * @param texture The texture.
 */
void render_init_color_texture(u32 *texture);

/**
 * Initializes the shaders.
 * @param state The internal render state.
 */
void render_init_shaders(RenderState_Internal *state);

/**
 * Creates a shader program.
 * @param path_vert The path to the vertex shader.
 * @param path_frag The path to the fragment shader.
 * @return The shader program.
 */
u32 render_shader_create(const char *path_vert, const char *path_frag);
