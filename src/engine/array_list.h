#pragma once

#include "types.h"

typedef struct array_list {
  usize len;
  usize capacity;
  usize item_size;
  void *items;
} ArrayList;

ArrayList *array_list_create(usize item_size, usize initial_capacity);
usize array_list_append(ArrayList *list, void *item);
void *array_list_get(ArrayList *list, usize index);
u8 array_list_remove(ArrayList *list, usize index);