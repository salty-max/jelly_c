cmake_minimum_required(VERSION 3.28)
project(main LANGUAGES C)

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
add_executable(main 
    src/main.c 
    src/shader.c 
    src/gl.c
)

# Add include directories
target_include_directories(main PRIVATE src include ${SDL2_SOURCE_DIR}/include)

# Link SDL2 libraries
target_link_libraries(main PRIVATE SDL2::SDL2 SDL2::SDL2main)

# Copy shaders to build/bin
add_custom_command(
    TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/src/shaders $<TARGET_FILE_DIR:main>/shaders
    COMMENT "Copying shaders to build directory"
)
