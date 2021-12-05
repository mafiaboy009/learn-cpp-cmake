#cmake version 3.16.3
cmake_minimum_required( VERSION 3.16 FATAL_ERROR )

project( agk )

set (CMAKE_CXX_STANDARD 14 )
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

#target_include_directories(test PRIVATE ${YOUR_DIRECTORY})

#add_subdirectory( common )
#add_subdirectory( external )
#add_subdirectory( plugins )
add_subdirectory( utilities )
add_subdirectory( src )

# add_executable( ${PROJECT_NAME} main.c )
