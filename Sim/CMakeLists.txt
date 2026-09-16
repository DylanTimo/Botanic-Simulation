cmake_minimum_required(VERSION 3.18)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

project(AstrobotanicaEngine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trova la libreria OpenGL nativa di sistema
find_package(OpenGL REQUIRED)

include(FetchContent)

# 1. Configura e scarica GLFW (disabilitando test ed esempi inutili)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.3.8
)
FetchContent_MakeAvailable(glfw)

# 2. Scarica GLM
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG        1.0.1
)
FetchContent_MakeAvailable(glm)

# Sorgenti
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

# Collegamento di GLFW, GLM e OpenGL
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glm::glm OpenGL::GL)
target_include_directories(${PROJECT_NAME} PRIVATE ${glfw_SOURCE_DIR}/include)