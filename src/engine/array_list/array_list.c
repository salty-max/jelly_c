#include <stdlib.h>
#include <string.h>

#include "../array_list.h"
#include "../util.h"
#include "../types.h"

ArrayList *array_list_create(usize item_size, usize initial_capacity) {
  ArrayList *list = malloc(sizeof(ArrayList));
  if (!list) {
    ERROR_RETURN(NULL, "Failed to allocate memory for ArrayList\n");
  }

  list->item_size = item_size;
  list->capacity = initial_capacity;
  list->len = 0;
  list->items = malloc(item_size * initial_capacity);
  if (!list->items) {
    free(list);
    ERROR_RETURN(NULL, "Failed to allocate memory for ArrayList\n");
  }
  return list;
}

usize array_list_append(ArrayList *list, void *item) {
  if (list->len >= list->capacity) {
    list->capacity = list->capacity > 0 ? list->capacity * 2 : 1;

    void *items = realloc(list->items, list->item_size * list->capacity);
    if (!items) {
      ERROR_RETURN(-1, "Failed to reallocate memory for ArrayList\n");
    }

    list->items = items;
  }

  usize index = list->len++;
  void *dest = (u8 *)list->items + index * list->item_size;
  memcpy(dest, item, list->item_size);
  return index;
}

void *array_list_get(ArrayList *list, usize index) {
  if (index >= list->len) {
    return NULL;
  }

  return (u8 *)list->items + index * list->item_size;
}

u8 array_list_remove(ArrayList *list, usize index) {
  if (list->len == 0) {
    ERROR_RETURN(1, "Cannot remove from empty ArrayList\n");
  }
  if (index >= list->len) {
    ERROR_RETURN(1, "Index out of bounds\n");
  }
  if (list->len == 1) {
    list->len = 0;
    return 0;
  }

  --list->len;

  u8 *item_ptr = (u8 *)list->items + index * list->item_size;
  u8 *end_ptr = (u8 *)list->items + list->len * list->item_size;
  memcpy(item_ptr, end_ptr, list->item_size);

  return 0;
}
