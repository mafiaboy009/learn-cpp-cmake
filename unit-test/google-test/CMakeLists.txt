project( learn-cpp-unit-test-google-test )

add_subdirectory( lib )
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/lib)
 
set( src 
    google-test-MyStack.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/myStack.cpp
    )

set( header
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/myStack.hpp
    )

add_executable( unitTestGoogleTest
    ${src}
    ${header} 
    )

target_include_directories( unitTestGoogleTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib )
target_link_libraries( unitTestGoogleTest PRIVATE unitTestGoogleTestLib ${GTEST_LIBRARIES} pthread) 
#target_link_libraries( stlPriorityQueue PRIVATE Threads::Threads )
