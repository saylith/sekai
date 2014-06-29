include_directories(${SEKAI_SOURCE_DIR}/units)

link_directories(${SEKAI_BINARY_DIR}/units)

add_library(map battlemap.cpp square.cpp)
