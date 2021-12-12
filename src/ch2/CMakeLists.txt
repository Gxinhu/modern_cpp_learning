cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS "-std=c++17")
project(modern_cpp_ch2)
find_package(fmt REQUIRED)
find_package(Eigen3 REQUIRED)
add_executable(main strength_variable.cc)

add_executable(type type_inference.cc)
target_link_libraries(type fmt::fmt)

add_executable(template template_test.cc)
target_link_libraries(template fmt::fmt Eigen3::Eigen)

add_executable(object object_oriented.cc)
target_link_libraries(object fmt::fmt Eigen3::Eigen)
add_executable(exercise exercise.cc)
