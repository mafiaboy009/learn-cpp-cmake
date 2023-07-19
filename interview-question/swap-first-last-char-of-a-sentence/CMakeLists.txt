project( learn-cpp-interview-question-swap-first-last-char-of-a-sentence )

set(
    src1
    swap-first-last-char-1.cpp
    )

set(
    src2
    swap-first-last-char-2.cpp
    )

set(
    header
    )

add_executable( 
    interviewQuestionSwapFirstLastChar1
    ${src1}
    ${header}
)

add_executable( 
    interviewQuestionSwapFirstLastChar2
    ${src2}
    ${header}
)
