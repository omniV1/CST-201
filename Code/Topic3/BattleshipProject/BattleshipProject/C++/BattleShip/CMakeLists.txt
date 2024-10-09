cmake_minimum_required(VERSION 3.27)
project(Anagrams LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

enable_testing()

# Add the path to Google Test
add_subdirectory(src)
add_subdirectory(tests)
