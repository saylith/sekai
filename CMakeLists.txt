cmake_minimum_required(VERSION 2.6)
SET(CMAKE_CXX_FLAGS "-std=c++0x")
project(SEKAI)

add_subdirectory(map)
add_subdirectory(units)
add_subdirectory(battle)

link_directories(${SEKAI_BINARY_DIR}/units ${SEKAI_BINARY_DIR}/map ${SEKAI_BINARY_DIR}/battle)

add_executable(main main.cpp)

target_link_libraries( main sfml-system sfml-window sfml-graphics sfml-audio battle map units)
