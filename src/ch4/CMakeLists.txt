cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS "-std=c++17")
project(modern_cpp_ch4)
find_package(fmt REQUIRED)
add_executable(learn_array constant_array.cc)
target_link_libraries(learn_array fmt::fmt)

add_executable(unorder unorder_array.cc)
target_link_libraries(unorder fmt::fmt)