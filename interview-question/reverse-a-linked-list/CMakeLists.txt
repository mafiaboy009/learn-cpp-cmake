project( learn-cpp-interview-question-reverse-a-linked-list )

set(
    src
    linkedlistClient.cpp
    )

set(
    header
    linkedlist.hpp
)

add_executable( interviewQuestionReverseALinkedList
    ${src} 
    ${header}
)
