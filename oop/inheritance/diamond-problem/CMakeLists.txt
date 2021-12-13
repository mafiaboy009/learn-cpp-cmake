project( learn-cpp-oop-inheritance-diamond-problem )

set(
    src1
    diamond-problem01.cpp
    )

set(
    src2
    diamond-problem02.cpp
    )

set(
    header
    )

add_executable(
    oopInheritanceDiamondProblem1
    ${src1}
    ${header}
    )

add_executable(
    oopInheritanceDiamondProblem2
    ${src2}
    ${header}
    )
