project( learn-cpp-idiom-named-constructor )

set(
    src1
    named-constructor-1.cpp
)

set(
    src2
    named-constructor-2.cpp
)

set(
    header
)

add_executable(
    idiomNamedConstructor1
    ${src1}
    ${header}
 )

add_executable(
    idiomNamedConstructor2
    ${src2}
    ${header}
)
