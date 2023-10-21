project( learn-cpp-integrate-apps-redis-db )

find_package(hiredis REQUIRED)

set( src redis-conn.cpp )

add_executable( integrateAppsRedisDB1 ${src} )
target_compile_options( integrateAppsRedisDB1 PUBLIC -fpermissive )
target_link_libraries( integrateAppsRedisDB1 PRIVATE ${hiredis_LIBRARIES} )