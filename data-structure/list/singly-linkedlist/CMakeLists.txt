project( learn-cpp-data-structure-list-singly-linkedlist )

set( src linkedlist.cpp )

set( header linkedlist.hpp )

include_directories( ${CMAKE_SOURCE_DIR}/data-structure/node/singly-node )
add_library( linkedlist SHARED ${header} ${src} )