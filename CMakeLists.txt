cmake_minimum_required(VERSION 3.15)
project(Blockchain)

set(CMAKE_CXX_STANDARD 14)

add_executable(Blockchain main.cpp Block/Block.h BlockChain/BlockChain.h Block/Block.cpp BlockChain/BlockChain.cpp hashFunction/helperHashFunctions.h hashFunction/helperHashFunctions.cpp hashFunction/hashFunction.cpp helperFunctions/helperFunctions.h helperFunctions/helperFunctions.cpp)