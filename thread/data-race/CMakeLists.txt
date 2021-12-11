project( learn-cpp-thread-data-race )

set( src 
    data-race.cpp
    )

set( header
    ${CMAKE_CURRENT_SOURCE_DIR}/../thread.hpp 
    )

add_executable( threadDataRace
    ${src}
    ${header} 
    )

target_include_directories( threadDataRace PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/.. )
target_link_libraries( threadDataRace PRIVATE Threads::Threads )

