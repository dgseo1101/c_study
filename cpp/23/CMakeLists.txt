set (TARGET_NAME "23")

file (GLOB SRCS 
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)
file (GLOB HDRS 
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
)

add_executable(${TARGET_NAME} ${SRCS} ${HDRS})