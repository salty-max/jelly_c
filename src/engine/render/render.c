#include <glad/gl.h>

#include "../global.h"
#include "../render.h"

#include "render_internal.h"

static RenderState_Internal state = {0};

void render_init(void) {
  global.render.width = 800;
  global.render.height = 600;
  global.render.window =
      render_init_window(global.render.width, global.render.height);

  render_init_quad(&state.vao_quad, &state.vbo_quad, &state.ebo_quad);
  render_init_shaders(&state);
  render_init_color_texture(&state.texture_color);
}

void render_begin(void) {
  glClearColor(17.0f / 255.0f, 17.0f / 255.0f, 27.0f / 255.0f, 1);
  glClear(GL_COLOR_BUFFER_BIT);
}

void render_end(void) { SDL_GL_SwapWindow(global.render.window); }

void render_shutdown(void) {
  glDeleteVertexArrays(1, &state.vao_quad);
  glDeleteBuffers(1, &state.vbo_quad);
  glDeleteBuffers(1, &state.ebo_quad);

  SDL_GL_DeleteContext(global.render.window);
  SDL_DestroyWindow(global.render.window);
  SDL_Quit();
}

void render_quad(Vec2 position, Vec2 size, Vec4 color) {
  glUseProgram(state.shader_default);

  Mat4 model = mat4_identity();
  mat4_translate(&model, position.x, position.y, 0);
  mat4_scale_aniso(&model, size.x, size.y, 1);

  glUniformMatrix4fv(glGetUniformLocation(state.shader_default, "model"), 1,
                     GL_FALSE, &model.m[0][0]);
  glUniform4fv(glad_glGetUniformLocation(state.shader_default, "color"), 1,
               &color);

  glBindVertexArray(state.vao_quad);

  glBindTexture(GL_TEXTURE_2D, state.texture_color);

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);

  glBindVertexArray(0);
}