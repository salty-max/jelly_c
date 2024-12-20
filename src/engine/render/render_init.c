#include <glad/gl.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include "../util.h"
#include "../global.h"

#include "render.h"
#include "render_internal.h"

SDL_Window *render_init_window(u32 width, u32 height) {
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    ERROR_EXIT("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  }

  SDL_Window *window =
      SDL_CreateWindow("Jelly", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       800, 600, SDL_WINDOW_OPENGL);

  if (!window) {
    ERROR_EXIT("Window could not be created! SDL_Error: %s\n", SDL_GetError());
  }

  SDL_GLContext context = SDL_GL_CreateContext(window);
  if (!gladLoaderLoadGL()) {
    ERROR_EXIT("Failed to load OpenGL!\n", SDL_GetError());
  }

  puts("OpenGL loaded successfully!");
  printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
  printf("Vendor: %s\n", glGetString(GL_VENDOR));
  printf("Renderer: %s\n", glGetString(GL_RENDERER));

  return window;
}

void render_init_quad(u32 *vao, u32 *vbo, u32 *ebo) {
  f32 vertices[] = {
      // x, y ,z, u, v
      0.5f,  0.5f,  0.0f, 0.0f, 0.0f, // top right
      0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, // bottom right
      -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, // bottom left
      -0.5f, 0.5f,  0.0f, 1.0f, 0.0f  // top left
  };

  u32 indices[] = {
      0, 1, 3, // first triangle
      1, 2, 3  // second triangle
  };

  glGenVertexArrays(1, vao);
  glGenBuffers(1, vbo);
  glGenBuffers(1, ebo);

  glBindVertexArray(*vao);

  glBindBuffer(GL_ARRAY_BUFFER, *vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);

  // xyz
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(f32),
                        (void *)NULL);
  glEnableVertexAttribArray(0);

  // uv
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(f32),
                        (void *)(3 * sizeof(f32)));
  glEnableVertexAttribArray(1);

  glBindVertexArray(0);
}