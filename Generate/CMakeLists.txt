cmake_minimum_required(VERSION 3.5)

project(Parks_Generator)


set(CMAKE_CXX_FLAGS "-std=c++11")
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

FIND_PACKAGE(Boost COMPONENTS unit_test_framework REQUIRED)
IF (Boost_FOUND)
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
  ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

add_library(ruleslib rules.cpp)
add_library(matlib matrix.cpp)
add_library(parklib park.cpp)
add_library(communitylib community.cpp
                         matrix.cpp
                         park.cpp)

add_executable(matrixtest matrix.test.cpp)
target_link_libraries(matrixtest LINK_PUBLIC matlib)
target_link_libraries(matrixtest LINK_PUBLIC ${Boost_LIBRARIES})

add_executable(parkstest park.test.cpp)
target_link_libraries(parkstest LINK_PUBLIC parklib)
target_link_libraries(parkstest LINK_PUBLIC ${Boost_LIBRARIES})

add_executable(communitytest community.test.cpp)
target_link_libraries(communitytest LINK_PUBLIC communitylib)
target_link_libraries(communitytest LINK_PUBLIC ${Boost_LIBRARIES})

add_executable(rulestest rules.test.cpp)
target_link_libraries(rulestest LINK_PUBLIC ruleslib)
target_link_libraries(rulestest LINK_PUBLIC ${Boost_LIBRARIES})
