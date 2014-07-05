include_directories(${SEKAI_SOURCE_DIR}/map ${SEKAI_SOURCE_DIR}/types/action)
SET(CMAKE_CXX_FLAGS "-std=c++0x")

link_directories(${SEKAI_BINARY_DIR}/map ${SEKAI_BINARY_DIR}/types/action)
add_library(battle battle.cpp)
target_link_libraries(battle action)
