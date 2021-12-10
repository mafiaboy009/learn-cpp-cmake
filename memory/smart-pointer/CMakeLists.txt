project( learn-cpp-memory-smart-pointer )

set(
    src
    smart-pointer.cpp
    )

set(
    header
    smart-pointer.hpp
    )

add_executable(
    memorySmartPointer
    ${src}
    ${header}
    )
