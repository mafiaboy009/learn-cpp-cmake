project( learn-cpp-data-structure-node-doublynode )

set( src doubly_node.cpp )

set( header doubly_node.hpp )

add_library( doublynode SHARED ${header} ${src} )