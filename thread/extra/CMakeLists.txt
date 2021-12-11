project( learn-cpp-thread-extra )

set( src 
    extra.cpp
    )

set( header
    ${CMAKE_CURRENT_SOURCE_DIR}/../thread.hpp 
    )

add_executable( threadExtra
    ${src}
    ${header} 
    )

target_include_directories( threadExtra PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/.. )
target_link_libraries( threadExtra PRIVATE Threads::Threads )

