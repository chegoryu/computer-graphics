cmake_minimum_required(VERSION 3.13)
project(ComputerGraphics CXX)

set(CMAKE_CXX_STANDARD_REQUIRED 14)

if (CMAKE_CXX_COMPILER_ID MATCHES "[cC][lL][aA][nN][gG]")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-deprecated -fdiagnostics-color=always -ggdb3 -pedantic -std=c++14 -framework GLUT -framework OpenGL -framework Cocoa")
else()
    message("[Warning]: You are building without clang c++ compiler, you may need to tune some things")
endif()

add_definitions(-DGL_GLEXT_PROTOTYPES)

set(CG_SRC libs/geometry/color.cpp
           libs/geometry/point.cpp
           libs/scene/scene.cpp
           src/main.cpp
           src/main_scene.cpp)

include_directories(libs)
add_executable(ComputerGraphics ${CG_SRC})
