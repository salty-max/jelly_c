#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "engine/global.h"
#include "math/vec.h"

int main(int argc, char *argv[]) {
  render_init();

  bool should_quit = false;

  while (!should_quit) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        should_quit = true;
        break;
      default:
        break;
      }
    }

    render_begin();

    render_quad(vec2(global.render.width * 0.5, global.render.height * 0.5),
                vec2(100, 100),
                vec4(148.0f / 255.0f, 226.0f / 255.0f, 213.0f / 255.0f, 1));

    render_end();
  }

  render_shutdown();
  return 0;
}
