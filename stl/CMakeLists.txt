project( learn-cpp-stl )

add_subdirectory( priority-queue )
#add_subdirectory( )

set( src
    stl-notes.cpp
    )

set( header
    )

add_executable( stlNotes
    ${src}
    ${header}
    )
