add_executable(part_1 "part 1/main.cpp")
# add_executable(part_2 "part 2/main.cpp")
configure_file(input ${CMAKE_CURRENT_BINARY_DIR}/Debug/input)
configure_file(input ${CMAKE_CURRENT_BINARY_DIR}/Release/input)
