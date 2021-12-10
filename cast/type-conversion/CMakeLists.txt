project( learn-cpp-cast-type-conversion )

set(
    src1
    implicit-standard.cpp
    )

set(
    src2
    implicit-user-defined-1.cpp
    )

set(
    src3
    implicit-user-defined-2.cpp
    )

set(
    header
    )

add_executable(
    castTypeConversionImplicitStandard
    ${src1}
    ${header}
    )

add_executable(
    castTypeConversionImplicitUserDefined1
    ${src2}
    ${header}
    )

add_executable(
    castTypeConversionImplicitUserDefined2
    ${src3}
    ${header}
    )
