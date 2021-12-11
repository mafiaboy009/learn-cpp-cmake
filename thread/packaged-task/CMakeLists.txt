project( learn-cpp-thread-packaged-task )

set( src 
    packaged-task.cpp
    )

set( header
    ${CMAKE_CURRENT_SOURCE_DIR}/../thread.hpp 
    )

add_executable( threadPackagedTask
    ${src}
    ${header} 
    )

target_include_directories( threadPackagedTask PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/.. )
target_link_libraries( threadPackagedTask PRIVATE Threads::Threads )

