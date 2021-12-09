project( learn-cpp-algorithm-template )

set(
    src1
    variadic.cpp
    )
#[[
set(
    src2
    random-2.cpp
    )
]]

set(
    header
    variadic.hpp
    )

add_executable( templateVariadic 
    ${src1} 
    ${header}
    )

#[[
add_executable( algorithmRandom2 
    ${src2} 
    ${header}
    )
]]
