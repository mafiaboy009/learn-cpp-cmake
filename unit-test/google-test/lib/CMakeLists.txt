project( learn-cpp-unit-test-google-test-lib )

set( src
    myStack.cpp
    )

set( header
    myStack.hpp
    )

add_library( 
    unitTestGoogleTestLib 
    ${src} 
    ${header}
    )

add_executable( unitTestGoogleClientToLib
    main.cpp
    ${src}
    ${header}
    )
