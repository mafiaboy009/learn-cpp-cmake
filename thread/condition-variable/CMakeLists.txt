project( learn-cpp-thread-condition-variable )

set( src 
    condition-variable.cpp
    )

set( header
    ${CMAKE_CURRENT_SOURCE_DIR}/../thread.hpp 
    )

add_executable( threadConditionVariable
    ${src}
    ${header} 
    )

target_include_directories( threadConditionVariable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/.. )
target_link_libraries( threadConditionVariable PRIVATE Threads::Threads )

