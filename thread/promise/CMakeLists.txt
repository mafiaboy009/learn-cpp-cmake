project( learn-cpp-thread-promise )

set( src 
    promise.cpp
    )

set( header
    ${CMAKE_CURRENT_SOURCE_DIR}/../thread.hpp 
    )

add_executable( threadPromise
    ${src}
    ${header} 
    )

target_include_directories( threadPromise PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/.. )
target_link_libraries( threadPromise PRIVATE Threads::Threads )
