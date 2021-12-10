project( learn-cpp-cast-const )

set(
    src1
    const-1.cpp
    )

set(
    src2
    const-2.cpp
    )

set(
    src3
    const-3.cpp
    )

set(
    src4
    const-4.cpp
    )

set(
    header
    )

add_executable(
    castConst1
    ${src1}
    ${header}
    )

add_executable(
    castConst2
    ${src2}
    ${header}
    )

add_executable(
    castConst3
    ${src3}
    ${header}
    )

add_executable(
    castConst4
    ${src4}
    ${header}
    )

