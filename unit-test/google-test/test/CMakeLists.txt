enable_testing()

project(AuraTest)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/lib)
 
set(test_HEADERS
        )

set(test_SOURCES
        testStack.cpp
         ${CMAKE_SOURCE_DIR}/lib/myStack.cpp
        )

add_executable(AuraTest ${test_SOURCES} ${test_HEADERS} ${mock_HEADERS})

target_include_directories(AuraTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR})
target_link_libraries(AuraTest PRIVATE auraLib ${GTEST_LIBRARIES} pthread) 
#target_link_libraries(AuraTest PRIVATE auraLib ${GTEST_LIBRARIES} gtest gmock pthread) 

# Link runTests with what we want to test and the GTest and pthread library
#target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
