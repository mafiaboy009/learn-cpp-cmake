project( learn-cpp-desgin-pattern-creational-builder )

set(
    src
    builder.cpp
    )

set(
    header
    builder.hpp
    )

add_executable(
    designPatternCreationalBuilder
    ${src}
    ${header}
    )
