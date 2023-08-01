project( learn-cpp-interview-question-linkedlist-client )

include_directories( ${CMAKE_SOURCE_DIR}/data-structure/list/singly-linkedlist ${CMAKE_SOURCE_DIR}/data-structure/node/singly-node )
set( src linkedlistClient.cpp )

link_directories( ${CMAKE_SOURCE_DIR}/lib )
add_executable( interviewQuestionLinkedlistClient ${src} )