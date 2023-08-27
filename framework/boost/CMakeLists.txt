project( learn-cpp-framework-boost )

find_package(Boost 1.56 REQUIRED COMPONENTS date_time filesystem iostreams)

set( src1 boost01.cpp )

#set( src2 poco02.cpp )

set( header )

add_executable( frameworkBoost1 ${src1} ${header} )

#add_executable( frameworkPoco2 ${src2} ${header} )

target_link_libraries(frameworkBoost1 PRIVATE Boost::date_time Boost::filesystem Boost::iostreams)