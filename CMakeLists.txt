cmake_minimum_required(VERSION 3.10)
project(TesterHugo)

# Add an executable target
add_executable(main main.cpp)

# Set C++ standard
set_target_properties(main PROPERTIES CXX_STANDARD 11)
