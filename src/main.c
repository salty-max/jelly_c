#include <stdio.h>
#include <stdlib.h>

#include <glad/gl.h>
#include <SDL.h>
#include <SDL_opengl.h>

#include <shader.h> // Include the shader utilities

const GLuint WIDTH = 800, HEIGHT = 600;

// Vertex data for a triangle
const float vertices[] = {
    // Positions        // Colors
    0.0f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, // Top
    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // Bottom Left
    0.5f,  -0.5f, 0.0f, 0.0f, 0.0f, 1.0f  // Bottom Right
};

int main(int argc, char *argv[]) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "SDL Init Error: %s\n", SDL_GetError());
    return -1;
  }

  // Set OpenGL attributes
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  // Create an SDL window
  SDL_Window *window =
      SDL_CreateWindow("[glad] GL with SDL and Shaders", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT,
                       SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

  if (!window) {
    fprintf(stderr, "SDL Window Error: %s\n", SDL_GetError());
    SDL_Quit();
    return -1;
  }

  // Create OpenGL context
  SDL_GLContext context = SDL_GL_CreateContext(window);
  if (!context) {
    fprintf(stderr, "SDL GL Context Error: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return -1;
  }

  // Initialize GLAD
  if (!gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress)) {
    fprintf(stderr, "Failed to initialize GLAD\n");
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return -1;
  }

  printf("OpenGL Version: %s\n", glGetString(GL_VERSION));

  // Compile and link shaders
  GLuint shader_program =
      create_shader_program("shaders/vertex.glsl", "shaders/fragment.glsl");

  // Create VAO and VBO
  GLuint VAO, VBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Vertex attribute: position
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  // Vertex attribute: color
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  // Main loop
  int exit = 0;
  while (!exit) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        exit = 1;
        break;
      case SDL_KEYUP:
        if (event.key.keysym.sym == SDLK_ESCAPE) {
          exit = 1;
        }
        break;
      default:
        break;
      }
    }

    // Clear screen
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Use the shader program and draw the triangle
    glUseProgram(shader_program);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    SDL_GL_SwapWindow(window);
    SDL_Delay(1);
  }

  // Cleanup
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteProgram(shader_program);

  SDL_GL_DeleteContext(context);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
