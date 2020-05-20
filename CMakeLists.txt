cmake_minimum_required(VERSION 3.16)
project(SearchEngine)

set(CMAKE_CXX_STANDARD 14)
include_directories(${CMAKE_BINARY_DIR}/lib)
add_executable(SearchEngine main.cpp DocumentParser.cpp lib/porter2_stemmer/porter2_stemmer.cpp porter2_stemmerWrapper.cpp porter2_stemmerWrapper.h SingletonStemmer.cpp SingletonStemmer.h WordIndex.cpp WordIndex.h Document.cpp Document.h)