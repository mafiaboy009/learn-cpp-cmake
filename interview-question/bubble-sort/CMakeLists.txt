project( learn-cpp-interview-question-bubble-sort )

set(
    src1
    bubble-sort-1.cpp
    )

set(
    src2
    bubble-sort-2.cpp
    )

set(
    header
    )

add_executable( interviewQuestionBubbleSort1
    ${src1} 
    ${header}
    )

add_executable( interviewQuestionBubbleSort2
    ${src2} 
    ${header}
    )
