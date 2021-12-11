project( learn-cpp-thread-dead-lock )

set( src 
    dead-lock.cpp
    )

set( header
    ${CMAKE_CURRENT_SOURCE_DIR}/../thread.hpp 
    )

add_executable( threadDeadLock
    ${src}
    ${header} 
    )

target_include_directories( threadDeadLock PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/.. )
target_link_libraries( threadDeadLock PRIVATE Threads::Threads )

