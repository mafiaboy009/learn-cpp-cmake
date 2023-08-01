project( learn-cpp-data-structure-node-singlynode )

set( src node.cpp )

set( header node.hpp )

add_library( singlynode SHARED ${header} ${src} )