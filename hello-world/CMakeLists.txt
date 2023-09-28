project( learn-cpp-hello-world )

set( src1 hello-world.cpp )
set( src2 minimal.cpp )

set( header )

add_executable( helloWorld ${src1} ${header} )
add_executable( minimalCpp ${src2} ${header} )