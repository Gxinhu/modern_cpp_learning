cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_TOOLCHAIN_FILE /workspace/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")
project(modern_cpp_ch3)
find_package(fmt REQUIRED)

add_executable(lambda lambda_learning.cc)
target_link_libraries(lambda fmt::fmt)

add_executable(function function_package.cc)
target_link_libraries(function fmt::fmt)

add_executable(right right_reference.cc)
target_link_libraries(right fmt::fmt)