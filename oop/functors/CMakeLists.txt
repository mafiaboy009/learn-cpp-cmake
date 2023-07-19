project( learn-cpp-oop-functors )

set(
    src1
    functor-1.cpp
    )

set(
    src2
    functor-2.cpp
    )

set(
    header
    )

add_executable(
    oopFunctors1
    ${src1}
    ${header}
    )

add_executable(
    oopFunctors2
    ${src2}
    ${header}
    )
