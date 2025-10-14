cmake_minimum_required(VERSION 3.14)
project(Basilisk)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add glad
add_library(glad STATIC include/glad/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# add stb
add_library(stb INTERFACE include/stb/stb_image.h)
target_include_directories(stb INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# get other includes glm, glfw
include(FetchContent)
add_subdirectory(include)

# Collect all cpp files except entry points
file(GLOB_RECURSE ENGINE_SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)
list(REMOVE_ITEM ENGINE_SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

# --- Make Example Executables ---
# Boilerplate Example
add_executable(01_boilerplate 01_boilerplate.cpp ${ENGINE_SRC})
target_include_directories(01_boilerplate PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(01_boilerplate glad glfw glm assimp stb)

# Abstract Boilerplate Example
add_executable(02_abstracted_boilerplate 02_abstracted_boilerplate.cpp ${ENGINE_SRC})
target_include_directories(02_abstracted_boilerplate PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(02_abstracted_boilerplate glad glfw glm assimp stb)

# Triangle Example
add_executable(03_triangle 03_triangle.cpp ${ENGINE_SRC})
target_include_directories(03_triangle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(03_triangle glad glfw glm assimp stb)

# Quad Example
add_executable(04_quad 04_quad.cpp ${ENGINE_SRC})
target_include_directories(04_quad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(04_quad glad glfw glm assimp stb)

# Color Example
add_executable(05_color_attrib 05_color_attrib.cpp ${ENGINE_SRC})
target_include_directories(05_color_attrib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(05_color_attrib glad glfw glm assimp stb)

# Texture Example
add_executable(06_texture 06_texture.cpp ${ENGINE_SRC})
target_include_directories(06_texture PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(06_texture glad glfw glm assimp stb)

# Transform Example
add_executable(07_transformation 07_transformation.cpp ${ENGINE_SRC})
target_include_directories(07_transformation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(07_transformation glad glfw glm assimp stb)

# Input Example
add_executable(08_input 08_input.cpp ${ENGINE_SRC})
target_include_directories(08_input PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(08_input glad glfw glm assimp stb)

# Cube Example
add_executable(09_cube 09_cube.cpp ${ENGINE_SRC})
target_include_directories(09_cube PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(09_cube glad glfw glm assimp stb)

# Camera Example
add_executable(10_camera 10_camera.cpp ${ENGINE_SRC})
target_include_directories(10_camera PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(10_camera glad glfw glm assimp stb)

# Mesh Example
add_executable(11_mesh 11_mesh.cpp ${ENGINE_SRC})
target_include_directories(11_mesh PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(11_mesh glad glfw glm assimp stb)

# Node Example
add_executable(12_node 12_node.cpp ${ENGINE_SRC})
target_include_directories(12_node PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(12_node glad glfw glm assimp stb)

# Instance Example
add_executable(13_instance 13_instance.cpp ${ENGINE_SRC})
target_include_directories(13_instance PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(13_instance glad glfw glm assimp stb)


# --- Copy shaders ---
set(SHADERS_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/shaders")
set(SHADERS_DST_DIR "${CMAKE_CURRENT_BINARY_DIR}/shaders")
file(GLOB_RECURSE SHADER_FILES "${SHADERS_SRC_DIR}/*")

add_custom_command( 
    OUTPUT ${SHADERS_DST_DIR}/.shader_copy_stamp
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${SHADERS_SRC_DIR} ${SHADERS_DST_DIR}
    COMMAND ${CMAKE_COMMAND} -E touch ${SHADERS_DST_DIR}/.shader_copy_stamp
    DEPENDS ${SHADER_FILES}
    COMMENT "Copying shaders to build directory"
)
add_custom_target(copy_shaders ALL DEPENDS ${SHADERS_DST_DIR}/.shader_copy_stamp)

# --- Copy textures ---
set(TEXTURES_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/textures")
set(TEXTURES_DST_DIR "${CMAKE_CURRENT_BINARY_DIR}/textures")
file(GLOB_RECURSE TEXTURE_FILES "${TEXTURES_SRC_DIR}/*")
add_custom_command(
    OUTPUT ${TEXTURES_DST_DIR}/.textures_copy_stamp
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${TEXTURES_SRC_DIR} ${TEXTURES_DST_DIR}
    COMMAND ${CMAKE_COMMAND} -E touch ${TEXTURES_DST_DIR}/.textures_copy_stamp
    DEPENDS ${TEXTURE_FILES}
    COMMENT "Copying textures to build directory"
)
add_custom_target(copy_textures ALL DEPENDS ${TEXTURES_DST_DIR}/.textures_copy_stamp)

# --- Copy models ---
set(MODELS_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/models")
set(MODELS_DST_DIR "${CMAKE_CURRENT_BINARY_DIR}/models")
file(GLOB_RECURSE MODEL_FILES "${MODELS_SRC_DIR}/*")
add_custom_command(
    OUTPUT ${MODELS_DST_DIR}/.models_copy_stamp
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${MODELS_SRC_DIR} ${MODELS_DST_DIR}
    COMMAND ${CMAKE_COMMAND} -E touch ${MODELS_DST_DIR}/.models_copy_stamp
    DEPENDS ${MODEL_FILES}
    COMMENT "Copying model to build directory"
)
add_custom_target(copy_models ALL DEPENDS ${MODELS_DST_DIR}/.models_copy_stamp)
