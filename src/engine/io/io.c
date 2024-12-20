#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "../types.h"
#include "../util.h"
#include "../io.h"

// 20 MiB
#define IO_READ_CHUNK_SIZE (20 * 1024 * 1024)
#define IO_READ_ERROR_GENERAL "Error reading file: %s. errno: %d\n"
#define IO_READ_ERROR_MEMORY "Not enough free memory to read file: %s\n"

File io_file_read(const char *path) {
  File file = {0};

  // Open the file
  FILE *fp = fopen(path, "rb");
  if (!fp) {
    perror("fopen failed");
    ERROR_RETURN(file, IO_READ_ERROR_GENERAL, path, errno);
  }

  // Determine file size
  fseek(fp, 0, SEEK_END);
  usize file_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  if (file_size == 0) {
    fclose(fp);
    ERROR_RETURN(file, "File is empty: %s\n", path);
  }

  // Allocate memory for the file contents
  char *data = malloc(file_size + 1); // +1 for null terminator
  if (!data) {
    fclose(fp);
    ERROR_RETURN(file, IO_READ_ERROR_MEMORY, path);
  }

  // Read the file into memory
  usize read_size = fread(data, 1, file_size, fp);
  if (read_size != file_size) {
    free(data);
    fclose(fp);
    ERROR_RETURN(file, IO_READ_ERROR_GENERAL, path, errno);
  }

  data[file_size] = '\0'; // Null-terminate the buffer

  // Populate the File struct
  file.data = data;
  file.size = file_size;
  file.is_valid = true;

  fclose(fp);
  return file;
}

int io_file_write(void *buffer, usize size, const char *path) {
  FILE *fp = fopen(path, "wb");
  if (!fp || ferror(fp)) {
    ERROR_RETURN(1, "Cannot write file: &s\n", path);
  }

  usize chunks_written = fwrite(buffer, 1, size, fp);

  fclose(fp);

  if (chunks_written != 1) {
    ERROR_RETURN(1,
                 "Write error. "
                 "Expected 1 chunk, got %zu\n",
                 chunks_written);
  }

  return 0;
}