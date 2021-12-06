project( learn-cpp-stl-priority-queue )

set( src 
    priority-queue.cpp
    )

set( header
    )

add_executable( stlPriorityQueue
    ${src}
    ${header} 
    )

#target_include_directories( stlPriorityQueue PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/.. )
#target_link_libraries( stlPriorityQueue PRIVATE Threads::Threads )

