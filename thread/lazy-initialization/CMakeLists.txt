project( learn-cpp-thread-lazy-initialization )

set( src 
    lazy-initialization.cpp
    )

set( header
    ${CMAKE_CURRENT_SOURCE_DIR}/../thread.hpp 
    )

add_executable( threadLazyInitialization
    ${src}
    ${header} 
    )

target_include_directories( threadLazyInitialization PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/.. )
target_link_libraries( threadLazyInitialization PRIVATE Threads::Threads )

