project( learn-cpp-interview-question-print-next-largest )

set(
    src1
    print-next-largest-using-queue.cpp
    )

set(
    src2
    print-next-largest-using-stack.cpp
    )

set(
    header
    )

add_executable( 
    interviewQuestionPrintNextLargestQueue
    ${src1}
    ${header}
    )

add_executable( 
    interviewQuestionPrintNextLargestStack
    ${src2}
    ${header}
    )
