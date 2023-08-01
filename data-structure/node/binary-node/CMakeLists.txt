project( learn-cpp-data-structure-node-binarynode )

set( src node.cpp )

set( header node.hpp )

add_library( binarynode SHARED ${header} ${src} )