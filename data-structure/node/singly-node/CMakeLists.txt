project( learn-cpp-data-structure-node-singlynode )

set( src singly_node.cpp )

set( header singly_node.hpp )

add_library( singlynode SHARED ${header} ${src} )