project( learn-cpp-qualifier-const )

set(
    src1
    const01.cpp
    )

set(
    header1
    )

set(
    src2
    const02.cpp
    )

set(
    header2
    const02.hpp
    )

add_executable(
    qualifierConst01
    ${src1}
    ${header1}
    )

add_executable(
    qualifierConst02
    ${src2}
    ${header2}
    )
