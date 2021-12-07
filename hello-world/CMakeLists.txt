project( learn-cpp-hello-world )

set( src 
    hello-world.cpp
    )

set( header
    )

add_executable( helloWorld
    ${src}
    ${header} 
    )
