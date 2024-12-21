#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "engine/global.h"
#include "engine/vec.h"
#include "engine/config.h"
#include "engine/input.h"
#include "engine/time.h"
#include "engine/physics.h"

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
  physics_init();

  u32 body_count = 100;

  for (u32 i = 0; i < body_count; ++i) {
    usize index = physics_body_create(vec2(rand() % (i32)global.render.width,
                                           rand() % (i32)global.render.height),
                                      vec2(rand() % 100, rand() % 100));
    Body *body = physics_body_get(index);
    body->acceleration = vec2(rand() % 200 - 100, rand() % 200 - 100);
  }

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
    physics_update();

    render_begin();

    render_quad(pos, vec2(50, 50),
                vec4(148.0f / 255.0f, 226.0f / 255.0f, 213.0f / 255.0f, 1));

    for (u32 i = 0; i < body_count; ++i) {
      Body *body = physics_body_get(i);
      render_quad(body->aabb.position, body->aabb.half_size,
                  vec4(243.0f / 255.0f, 139.0f / 255.0f, 168.0f / 255.0f, 1));

      if (body->aabb.position.x < 0 ||
          body->aabb.position.x > global.render.width) {
        body->velocity.x *= -1;
      }
      if (body->aabb.position.y < 0 ||
          body->aabb.position.y > global.render.height) {
        body->velocity.y *= -1;
      }

      if (body->velocity.x > 500) {
        body->velocity.x = 500;
      }
      if (body->velocity.x < -500) {
        body->velocity.x = -500;
      }
      if (body->velocity.y > 500) {
        body->velocity.y = 500;
      }
      if (body->velocity.y < -500) {
        body->velocity.y = -500;
      }
    }

    render_end();
    time_update_late();
  }

  render_shutdown();
  return 0;
}
