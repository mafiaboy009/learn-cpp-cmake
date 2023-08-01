project( learn-cpp-data-structure-node-doublynode )

set( src node.cpp )

set( header node.hpp )

add_library( doublynode SHARED ${header} ${src} )