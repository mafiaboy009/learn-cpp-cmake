project( learn-cpp-framework-boost )

find_package(Boost 1.83 REQUIRED COMPONENTS 
atomic
chrono container context coroutine contract
date_time
fiber filesystem 
graph
iostreams
json
locale log_setup log
math_c99f math_c99l math_c99 math_tr1f math_tr1l math_tr1
nowide
prg_exec_monitor program_options
random regex
serialization stacktrace_noop stacktrace_windbg_cached stacktrace_windbg system
thread timer type_erasure
unit_test_framework url
wave wserialization)

set( src1 boost01-date.cpp )

set( src2 boost02-asio.cpp )

set( src3 boost03-server.cpp )

set( header )

add_executable( frameworkBoost01Date ${src1} ${header} )
add_executable( frameworkBoost02Asio ${src2} ${header} )
add_executable( frameworkBoost03Server ${src3} ${header} )

target_link_libraries(frameworkBoost01Date PRIVATE Boost::date_time Boost::filesystem Boost::iostreams)
target_link_libraries(frameworkBoost02Asio PRIVATE Boost::boost Boost::thread Boost::system wsock32)
target_link_libraries(frameworkBoost03Server PRIVATE Boost::boost Boost::thread Boost::system wsock32 ws2_32)