add_executable(day_1_part_1 part_1/main.cpp)
add_executable(day_1_part_2 part_2/main.cpp)
configure_file(input ${CMAKE_CURRENT_BINARY_DIR}/Debug/input)
configure_file(input ${CMAKE_CURRENT_BINARY_DIR}/Release/input)
