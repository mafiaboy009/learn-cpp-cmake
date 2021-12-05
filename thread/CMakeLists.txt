project( learn-cpp-thread )

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

#add_subdirectory( async             )
add_subdirectory( basic             )
#add_subdirectory( condition-variable)
add_subdirectory( data-race          )
#add_subdirectory( future            )
#add_subdirectory( mutex             )
#add_subdirectory( promise           )
#add_subdirectory( summary           )
#add_subdirectory( )
