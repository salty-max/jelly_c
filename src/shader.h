#ifndef SHADER_H
#define SHADER_H

#include <glad/gl.h>

/**
 * Reads, compiles, and returns a shader object from the given file.
 *
 * @param filepath Path to the shader file.
 * @param type The type of the shader (e.g., GL_VERTEX_SHADER,
 * GL_FRAGMENT_SHADER).
 * @return The compiled shader object ID, or 0 on failure.
 */
GLuint compile_shader(const char *filepath, GLenum type);

/**
 * Creates a shader program by linking a vertex shader and a fragment shader.
 *
 * @param vertex_path Path to the vertex shader file.
 * @param fragment_path Path to the fragment shader file.
 * @return The linked shader program ID, or 0 on failure.
 */
GLuint create_shader_program(const char *vertex_path,
                             const char *fragment_path);

#endif // SHADER_H
