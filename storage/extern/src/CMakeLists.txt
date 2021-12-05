project( agkSrc )
#project( agkSrc CXX HXX)

#set_target_properties(agkExe PROPERTIES LINKER_LANGUAGE HPP)

set(srcs ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp )
set( headers )

add_executable( agkExe ${srcs} ${headers} )
target_link_libraries( agkExe  agkconstants )
# add_executable( ${PROJECT_NAME} main.c )
