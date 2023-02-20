cmake_minimum_required(VERSION 3.24)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_COMPILER c++)
add_compile_options(-Wall -Wextra -Werror)
include_directories(inc)

add_executable(ft_containers
		src/test_vector.cpp)
