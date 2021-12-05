project(AuraLib)

set(lib_SRCS
        myStack.cpp
        )
set(lib_HEADERS
    myStack.hpp
        )

add_library(auraLib ${lib_SRCS} ${lib_HEADERS})
