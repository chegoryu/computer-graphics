cmake_minimum_required(VERSION 3.13)
project(ComputerGraphics CXX)

set(CMAKE_CXX_STANDARD_REQUIRED 14)
set(CMAKE_C_STANDARD_REQUIRED 14)

if (CMAKE_COMPILER_IS_CLANGCXX)
      set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -fdiagnostics-color=always -ggdb3 -pedantic -framework GLUT -framework OpenGL -framework Cocoa")
else()
    message("[Warning]: You are building without clang c++ compiler, you may need to tune some things")
endif()

set(CG_SRC src/main.cpp
           src/main_scene.cpp
           libs/scene.cpp)

include_directories(libs)
add_executable(ComputerGraphics ${CG_SRC})
