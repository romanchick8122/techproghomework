cmake_minimum_required(VERSION 3.0)

option(ARM_BUILD "ON if building for arm" OFF)
option(TOOLCHAIN "Path to compiler toolchain")
option(CMAKE_INSTALL_PREFIX "Path to install prefix")
set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-c++)

project(SimpleLibrary)

include_directories(include)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)
add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

target_link_libraries(MainLib buffer)