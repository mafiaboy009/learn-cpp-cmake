project( learn-cpp-interview-question-reverse-words-in-a-sentence )

set(
    src1
    reverse-words-in-a-sentence01.cpp
    )

set(
    src2
    reverse-words-in-a-sentence02.cpp
    )

set(
    header
    )

add_executable( interviewQuestionReverseWordsInASentence1
    ${src1} 
    ${header}
    )

add_executable( interviewQuestionReverseWordsInASentence2
    ${src2} 
    ${header}
    )
