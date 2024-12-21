#pragma once

#include "types.h"

typedef struct time_state {
  f32 delta;       // Time since last frame
  f32 now;         // Time of current frame
  f32 last;        // Time of last frame
  f32 frame_last;  // Last time frame rate was calculated
  f32 frame_delay; // Maximum time between frames
  f32 frame_time;  // How long a frame should take

  u32 frame_rate;  // Current frame rate
  u32 frame_count; // Number of frames since last frame rate calculation
} TimeState;

void time_init(u32 frame_rate);
void time_update(void);
void time_update_late(void);