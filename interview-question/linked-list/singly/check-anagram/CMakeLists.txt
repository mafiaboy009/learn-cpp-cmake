project( learn-cpp-interview-question-linkedlist-check-anagram )

include_directories( ${CMAKE_SOURCE_DIR}/data-structure/list/singly-linkedlist ${CMAKE_SOURCE_DIR}/data-structure/node/singly-node )
set( src check-anagram.cpp )

add_executable( interviewQuestionLinkedlistCheckAnagram ${src} )