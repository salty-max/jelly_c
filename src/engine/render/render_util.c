#include <glad/gl.h>
#include <stdio.h>

#include "../util.h"
#include "../io.h"

#include "render_internal.h"

u32 render_shader_create(const char *path_vert, const char *path_frag) {
  int success;
  char log[512];

  // Read and compile vertex shader
  File file_vertex = io_file_read(path_vert);
  if (!file_vertex.is_valid) {
    ERROR_EXIT("Failed to read vertex shader: %s\n", path_vert);
  }

  u32 shader_vertex = glCreateShader(GL_VERTEX_SHADER);
  const char *vertex_source = file_vertex.data; // Use pointer to shader source
  glShaderSource(shader_vertex, 1, &vertex_source, NULL);
  glCompileShader(shader_vertex);
  glGetShaderiv(shader_vertex, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader_vertex, sizeof(log), NULL, log);
    ERROR_EXIT("Failed to compile vertex shader: %s\n%s\n", path_vert, log);
  }

  // Read and compile fragment shader
  File file_fragment = io_file_read(path_frag);
  if (!file_fragment.is_valid) {
    ERROR_EXIT("Failed to read fragment shader: %s\n", path_frag);
  }

  u32 shader_fragment = glCreateShader(GL_FRAGMENT_SHADER);
  const char *fragment_source =
      file_fragment.data; // Use pointer to shader source
  glShaderSource(shader_fragment, 1, &fragment_source, NULL);
  glCompileShader(shader_fragment);
  glGetShaderiv(shader_fragment, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader_fragment, sizeof(log), NULL, log);
    ERROR_EXIT("Failed to compile fragment shader: %s\n%s\n", path_frag, log);
  }

  // Link shaders into program
  u32 shader = glCreateProgram();
  glAttachShader(shader, shader_vertex);
  glAttachShader(shader, shader_fragment);
  glLinkProgram(shader);
  glGetProgramiv(shader, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shader, sizeof(log), NULL, log);
    ERROR_EXIT("Failed to link shader:\n%s\n", log);
  }

  // Clean up resources
  glDeleteShader(shader_vertex);
  glDeleteShader(shader_fragment);

  free(file_vertex.data);
  free(file_fragment.data);

  return shader;
}
