cmake_minimum_required (VERSION 3.5)

project (Ball)

set (CMAKE_CXX_STANDARD 17)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB_RECURSE source_files "${source_dir}/*.cpp")
message(${source_files})
add_executable (Ball ${source_files})
