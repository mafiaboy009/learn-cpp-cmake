project( learn-cpp-oop-class-string )

set( src 
	stringClass.cpp
	stringClient.cpp
    )

set( header
	stringClass.hpp
    )

add_executable( stringClass
    ${src}
    ${header} 
    )
