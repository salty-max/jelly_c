#include "shader.h"
#include <glad/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *read_file(const char *filepath) {
  FILE *file = fopen(filepath, "r");
  if (!file) {
    fprintf(stderr, "Failed to open file: %s\n", filepath);
    return NULL;
  }

  fseek(file, 0, SEEK_END);
  long length = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *buffer = malloc(length + 1);
  fread(buffer, 1, length, file);
  buffer[length] = '\0';

  fclose(file);
  return buffer;
}

GLuint compile_shader(const char *filepath, GLenum type) {
  char *source = read_file(filepath);
  if (!source)
    return 0;

  GLuint shader = glCreateShader(type);
  glShaderSource(shader, 1, (const char **)&source, NULL);
  glCompileShader(shader);

  int success;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    char info_log[512];
    glGetShaderInfoLog(shader, 512, NULL, info_log);
    fprintf(stderr, "Shader compilation failed (%s): %s\n", filepath, info_log);
  }

  free(source);
  return shader;
}

GLuint create_shader_program(const char *vertex_path,
                             const char *fragment_path) {
  GLuint vertex_shader = compile_shader(vertex_path, GL_VERTEX_SHADER);
  GLuint fragment_shader = compile_shader(fragment_path, GL_FRAGMENT_SHADER);

  GLuint program = glCreateProgram();
  glAttachShader(program, vertex_shader);
  glAttachShader(program, fragment_shader);
  glLinkProgram(program);

  int success;
  glGetProgramiv(program, GL_LINK_STATUS, &success);
  if (!success) {
    char info_log[512];
    glGetProgramInfoLog(program, 512, NULL, info_log);
    fprintf(stderr, "Shader linking failed: %s\n", info_log);
  }

  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);

  return program;
}
