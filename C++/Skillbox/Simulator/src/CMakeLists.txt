cmake_minimum_required(VERSION 3.28.0)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Simulator main.cpp ${INCLUDE_DIR}/commands.h ${INCLUDE_DIR}/struct.h)
target_include_directories(Simulator PUBLIC ${INCLUDE_DIR})

