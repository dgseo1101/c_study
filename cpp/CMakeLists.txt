cmake_minimum_required (VERSION 3.16)

project(CStudy)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set (CMAKE_CXX_FLAGS "-std=c++17 ${CMAKE_CXX_FLAGS}")
endif()

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")    
endif(MSVC)

add_subdirectory(hello_world)
add_subdirectory(01_helloworld)
add_subdirectory(02_namespace)