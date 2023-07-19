project( learn-cpp-oop-overloading-operators )

set(
    src1
    opertor-overloading-1.cpp
    )

set(
    src2
    opertor-overloading-2.cpp
    )

set(
    header
    )

add_executable(
    oopOverloadingOperators1
    ${src1}
    ${header}
    )

add_executable(
    oopOverloadingOperators2
    ${src2}
    ${header}
    )
