project( learn-cpp-cast-dynamic )

set(
    src
    dynamic.cpp
    )

set(
    header
    dynamic.hpp
    )

add_executable(
    castDynamic
    ${src}
    ${header}
    )
