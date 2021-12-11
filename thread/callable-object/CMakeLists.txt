project( learn-cpp-thread-callable-object )

set( src 
    callable-object.cpp
    )

set( header
    ${CMAKE_CURRENT_SOURCE_DIR}/../thread.hpp 
    )

add_executable( threadCallableObject
    ${src}
    ${header} 
    )

target_include_directories( threadCallableObject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/.. )
target_link_libraries( threadCallableObject PRIVATE Threads::Threads )

