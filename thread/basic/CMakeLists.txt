project( learn-cpp-thread-basic )

set( src 
    basic.cpp
    )

set( header
    ${CMAKE_CURRENT_SOURCE_DIR}/../thread.hpp 
    )

add_executable( threadBasic
    ${src}
    ${header} 
    )

target_include_directories( threadBasic PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/.. )
target_link_libraries( threadBasic PRIVATE Threads::Threads )

