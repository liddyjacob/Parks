cmake_minimum_required(VERSION 3.5)

project(Parks_Generator)


set(CMAKE_CXX_FLAGS "-std=c++11")
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

FIND_PACKAGE(Boost COMPONENTS unit_test_framework REQUIRED)
IF (Boost_FOUND)
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
  ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

add_library(libparks matrix.cpp)

add_executable(matrixtest matrix.test.cpp)
target_link_libraries(matrixtest LINK_PUBLIC libparks)
target_link_libraries(matrixtest LINK_PUBLIC ${Boost_LIBRARIES})
