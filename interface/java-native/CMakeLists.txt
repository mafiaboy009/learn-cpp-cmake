project( learn-cpp-interface-java-native )

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})

set( 
    src
    cppNative.cpp
    )

add_library( cppNative SHARED ${src} )
