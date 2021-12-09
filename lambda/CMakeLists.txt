project( learn-cpp-lambda )

set(
    src1
    lambda-1.cpp
    )

set(
    src2
    lambda-2.cpp
    )

set(
    src3
    lambda-3.cpp
    )

set(
    src4
    lambda-4.cpp
    )

set(
    header
    lambda.hpp
    )

add_executable(
    lambda1
    ${src1}
    ${header}
    )

add_executable(
    lambda2
    ${src2}
    ${header}
    )

add_executable(
    lambda3
    ${src3}
    ${header}
    )

add_executable(
    lambda4
    ${src4}
    ${header}
    )
