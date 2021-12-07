project( learn-cpp-desgin-pattern-structural-decorator )

set(
    src1
    decorator1.cpp
    )

set(
    src2
    decorator2.cpp
    )

set(
    header
    decorator2.hpp
    )

add_executable(
    designPatternStructuralDecorator1
    ${src1}
    ${header}
    )

add_executable(
    designPatternStructuralDecorator2
    ${src2}
    ${header}
    )
