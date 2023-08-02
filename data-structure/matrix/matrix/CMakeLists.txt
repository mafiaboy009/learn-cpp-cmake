project( learn-cpp-data-structure-matrix-ordinary )

set( src matrix.cpp )

set( header matrix.hpp )

add_library( ordinarymatrix SHARED ${header} ${src} )