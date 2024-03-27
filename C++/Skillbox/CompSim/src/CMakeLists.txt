cmake_minimum_required(VERSION 3.28.0)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_executable(CompSim main.cpp cpu.cpp disk.cpp gpu.cpp kbd.cpp ram.cpp command.cpp ${INCLUDE_DIR}/cpu.h ${INCLUDE_DIR}/disk.h ${INCLUDE_DIR}/gpu.h ${INCLUDE_DIR}/kbd.h ${INCLUDE_DIR}/ram.h ${INCLUDE_DIR}/command.h)
target_include_directories(CompSim PUBLIC ${INCLUDE_DIR})