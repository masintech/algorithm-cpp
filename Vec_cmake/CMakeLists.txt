Project(Vec2D)
cmake_minimum_required(VERSION 3.16)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Release")

#tell cmake to toutput binaries here:
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# tell cmake where to look for *.h files
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/Utils)

# create libraries 
ADD_LIBRARY(Utils SHARED Utils/Utils.cpp)
ADD_LIBRARY(Vec2D SHARED Utils/Vec2D.cpp)
TARGET_LINK_LIBRARIES(Vec2D Utils)

# add executable main
add_executable(main src/main.cpp)

# tell the linker to bind these objects together
target_link_libraries(main Vec2D)


