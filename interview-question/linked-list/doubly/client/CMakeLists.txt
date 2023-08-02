project( learn-cpp-interview-question-linkedlist-client )

include_directories( ${CMAKE_SOURCE_DIR}/data-structure/list/doubly-linkedlist ${CMAKE_SOURCE_DIR}/data-structure/node/doubly-node )
set( src doublyLinkedlistClient.cpp )

link_directories( ${CMAKE_SOURCE_DIR}/lib )
add_executable( interviewQuestionDoublyLinkedlistClient ${src} )