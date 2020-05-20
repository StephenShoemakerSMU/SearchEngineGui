cmake_minimum_required(VERSION 3.16)
project(SearchEngine)

set(CMAKE_CXX_STANDARD 14)
include_directories(/home/stephenshoemaker/Documents/Code/SearchEngine/src/C++/lib/rapidjson)
add_executable(SearchEngine main.cpp DocumentParser.cpp)