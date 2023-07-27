project( learn-cpp-interview-question-evaluate-postfix-expression  )

set( src1 evaluate-postfix-expr-using-stack-v1.cpp )

set( src2 evaluate-postfix-expr-using-stack-v2.cpp )

set( header )

add_executable( interviewQuestionEvaluatePostfixExprV1 ${src1} ${header} )
add_executable( interviewQuestionEvaluatePostfixExprV2 ${src2} ${header} )