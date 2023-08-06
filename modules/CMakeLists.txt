cmake_minimum_required( VERSION 3.16 FATAL_ERROR )

project( learn-cpp-cmake-modules )

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  include(gcc_modules.cmake)
endif()

set (CMAKE_CXX_STANDARD 20 )
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
# turn on the experimental API
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API  "2182bf5c-ef0d-489a-91da-49dbc3090d2a")


set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules-ts")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -x c++-system-header iostream")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/modules )
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/modules )
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/modules )
set (CMAKE_OBJECT_PATH_MAX 500)
set (CMAKE_VERBOSE_MAKEFILE OFF)

set ( src helloworld.cpp main.cpp )
set ( header )
add_executable( modulesCpp ${src} ${header} )