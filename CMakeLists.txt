cmake_minimum_required(VERSION 2.6)
SET(CMAKE_CXX_FLAGS "-std=c++0x")
project(SEKAI)
set(CMAKE_AUTOMOC ON)
add_subdirectory(map)
add_subdirectory(units)
add_subdirectory(battle)
add_subdirectory(types)
add_subdirectory(types/action)

link_directories(${SEKAI_BINARY_DIR}/units ${SEKAI_BINARY_DIR}/map ${SEKAI_BINARY_DIR}/battle ${SEKAI_BINARY_DIR}/types ${SEKAI_BINARY_DIR}/types/action)

add_executable(main main.cpp)

target_link_libraries( main sfml-system sfml-window sfml-graphics sfml-audio battle map units action)
