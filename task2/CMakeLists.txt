cmake_minimum_required (VERSION 3.17)

project("task2")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

find_package(Threads)

find_package(GTest)
include_directories(${GTEST_INCLUDE_DIRS})

add_custom_target(generateIndex ALL	DEPENDS ${CMAKE_SOURCE_DIR}/A/index.h VERBATIM)
add_custom_command(PRE_BUILD
		OUTPUT ${CMAKE_SOURCE_DIR}/A/index.h
		COMMAND python3 ${CMAKE_SOURCE_DIR}/A/preparing.py
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/A/
		VERBATIM)

add_subdirectory(B)
set_target_properties(B PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

include_directories(${CMAKE_SOURCE_DIR})
add_executable(C C/main.cpp)
add_dependencies(C generateIndex)
target_link_libraries(C B)

add_executable(CTest C/main_test.cpp)
add_dependencies(CTest generateIndex)
target_link_libraries(CTest B)
target_link_libraries(CTest ${GTEST_LIBRARIES} Threads::Threads)

