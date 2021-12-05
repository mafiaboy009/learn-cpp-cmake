project( learn-cpp-thread-basic )

set( src 
    unique-lock.cpp
    )

set( header
    ${CMAKE_CURRENT_SOURCE_DIR}/../thread.hpp 
    )

add_executable( threadUniqueLock
    ${src}
    ${header} 
    )

target_include_directories( threadUniqueLock PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/.. )
target_link_libraries( threadUniqueLock PRIVATE Threads::Threads )

