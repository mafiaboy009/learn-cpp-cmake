project( learn-cpp-interview-question-count-numbers-less-than-a-particular-number )

set(
    src1
    count-numbers-less-than-a-particular-number.cpp
    )

#[[
set(
    src2
    )
]]

set(
    header
    count-numbers-less-than-a-particular-number.hpp
    )

add_executable( interviewQuestionCountNumbersLessThanAParticularNumber
    ${src1} 
    ${header}
    )

#[[
add_executable( interviewQuestionBubbleSort2
    ${src2} 
    ${header}
    )
]]
