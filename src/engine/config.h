#pragma once

#include "input.h"
#include "types.h"

typedef struct config {
  u32 keybinds[5];
} ConfigState;

void config_init(void);
void config_key_bind(InputKey key, const char *key_name);
