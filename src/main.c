#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "engine/global.h"
#include "engine/vec.h"
#include "engine/config.h"
#include "engine/input.h"
#include "engine/time.h"

static bool should_quit = false;
static Vec2 pos;

static void input_handle(void) {
  if (global.input.left == KS_PRESSED || global.input.left == KS_HELD) {
    pos.x -= 500 * global.time.delta;
  }
  if (global.input.right == KS_PRESSED || global.input.right == KS_HELD) {
    pos.x += 500 * global.time.delta;
  }
  if (global.input.up == KS_PRESSED || global.input.up == KS_HELD) {
    pos.y += 500 * global.time.delta;
  }
  if (global.input.down == KS_PRESSED || global.input.down == KS_HELD) {
    pos.y -= 500 * global.time.delta;
  }
  if (global.input.escape == KS_PRESSED) {
    should_quit = true;
  }
}

int main(int argc, char *argv[]) {
  time_init(60);
  config_init();
  render_init();

  pos = vec2(global.render.width * 0.5, global.render.height * 0.5);

  while (!should_quit) {
    time_update();

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

    input_update();
    input_handle();

    render_begin();

    render_quad(pos, vec2(50, 50),
                vec4(148.0f / 255.0f, 226.0f / 255.0f, 213.0f / 255.0f, 1));

    render_end();
    time_update_late();
  }

  render_shutdown();
  return 0;
}
