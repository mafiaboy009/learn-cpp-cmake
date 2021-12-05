project(AuraClient)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/lib )

set(Aura-SRCS
        main.cpp)

add_executable(Aura ${Aura-SRCS} )
target_link_libraries(Aura auraLib)
