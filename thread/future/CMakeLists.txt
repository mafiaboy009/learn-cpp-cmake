project( learn-cpp-thread-future )

set( src 
    future.cpp
    )

set( header
    ${CMAKE_CURRENT_SOURCE_DIR}/../thread.hpp 
    )

add_executable( threadFuture
    ${src}
    ${header} 
    )

target_include_directories( threadFuture PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/.. )
target_link_libraries( threadFuture PRIVATE Threads::Threads )

