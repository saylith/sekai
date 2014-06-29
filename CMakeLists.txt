cmake_minimum_required(VERSION 2.6)
project(SEKAI)

add_subdirectory(map)
add_subdirectory(units)

link_directories(${SEKAI_BINARY_DIR}/units ${SEKAI_BINARY_DIR}/map)

add_executable(main main.cpp)

target_link_libraries( main sfml-system sfml-window sfml-graphics sfml-audio map units)
