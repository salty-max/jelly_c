#include <glad/gl.h>

#include "../global.h"
#include "render.h"
#include "render_internal.h"

static RenderState_Internal state = {0};

void render_init(void) {
  global.render.width = 800;
  global.render.height = 600;
  global.render.window =
      render_init_window(global.render.width, global.render.height);

  render_init_quad(&state.vao_quad, &state.vbo_quad, &state.ebo_quad);
}

void render_begin(void) {
  glClearColor(0.08, 0.1, 0.1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
}

void render_end(void) { SDL_GL_SwapWindow(global.render.window); }

void render_shutdown(void) {
  glDeleteVertexArrays(1, &state.vao_quad);
  glDeleteBuffers(1, &state.vbo_quad);
  glDeleteBuffers(1, &state.ebo_quad);

  SDL_GL_DeleteContext(global.render.window);
}

void render_quad(Vec2 position, Vec2 size, Vec4 color) {
  glBindVertexArray(state.vao_quad);

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);

  glBindVertexArray(0);
}