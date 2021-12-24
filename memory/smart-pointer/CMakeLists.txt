project( learn-cpp-memory-smart-pointer )

set(
    src1
    smart-pointer01.cpp
    )

set(
    src2
    smart-pointer02.cpp
    )

set(
    header1
    smart-pointer01.hpp
    )

add_executable(
    memorySmartPointer1
    ${src1}
    ${header1}
    )

add_executable(
    memorySmartPointer2
    ${src2}
    )
