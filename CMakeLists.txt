cmake_minimum_required(VERSION 3.28)
project(jelly LANGUAGES C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)

# Fetch SDL2
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.30.10
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(SDL2)

# Define executable
add_executable(jelly 
    src/main.c 
    src/gl.c
    src/math/mat.c
    src/math/vec.c
    src/engine/global.c
    src/engine/io/io.c
    src/engine/render/render.c
    src/engine/render/render_init.c
    src/engine/render/render_util.c
)

add_executable(test_mat src/test/test_mat.c src/math/mat.c)
add_executable(test_vec src/test/test_vec.c src/math/vec.c)

# Add include directories
target_include_directories(jelly PRIVATE src include ${SDL2_SOURCE_DIR}/include)
target_include_directories(test_mat PRIVATE src include)
target_include_directories(test_vec PRIVATE src include)

if(WIN32)
    # Windows: Link SDL2 libraries only
    target_link_libraries(jelly PRIVATE SDL2::SDL2 SDL2::SDL2main)
else()
    # Non-Windows: Link SDL2 and Math libraries
    target_link_libraries(jelly PRIVATE SDL2::SDL2 SDL2::SDL2main m)
    target_link_libraries(test_mat PRIVATE m)
    target_link_libraries(test_vec PRIVATE m)
endif()

# Copy shaders to build/bin
add_custom_command(
    TARGET jelly POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/src/shaders $<TARGET_FILE_DIR:jelly>/shaders
    COMMENT "Copying shaders to build directory"
)
