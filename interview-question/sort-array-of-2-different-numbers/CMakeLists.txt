project( learn-cpp-interview-question-sort-array-of-2-different-numbers )

set(
    src1
    sort-array-of-2-different-numbers01.cpp
    )

set(
    src2
    sort-array-of-2-different-numbers02.cpp
    )

set(
    header
    )

add_executable( interviewQuestionSortArrayOf2DiffNumbers1
    ${src1} 
    ${header}
    )

add_executable( interviewQuestionSortArrayOf2DiffNumbers2
    ${src2} 
    ${header}
    )
