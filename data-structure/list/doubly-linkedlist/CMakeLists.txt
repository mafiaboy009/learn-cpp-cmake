project( learn-cpp-data-structure-list-doubly-linked )

set( src doubly-linked.cpp )

set( header doubly-linked.hpp )

include_directories( ${CMAKE_SOURCE_DIR}/data-structure/node/doubly-node )
add_library( dataStructureListDoublyLinked ${src} ${header} )
