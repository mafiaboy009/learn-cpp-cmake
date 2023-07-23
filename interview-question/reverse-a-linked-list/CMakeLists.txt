project( learn-cpp-interview-question-reverse-a-linked-list )

#set( srcLib1 node.cpp )
#set( srcLib1 )
set( headerLib1 node.hpp )
#add_library( node SHARED ${headerLib1} )

#set( srcLib2 linkedlist.cpp )
#set( srcLib2 )
set( headerLib2 linkedlist.hpp )
#add_library( linkedlist SHARED ${headerLib2} )
#target_link_libraries( linkedlist PRIVATE node ) 

set( src linkedlistClient.cpp )
add_executable( interviewQuestionReverseALinkedList ${headerLib1} ${headerLib2} ${src} )
#target_include_directories( interviewQuestionReverseALinkedList PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib )
#target_link_libraries( interviewQuestionReverseALinkedList PRIVATE node linkedlist )