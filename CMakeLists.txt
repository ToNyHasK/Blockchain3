cmake_minimum_required(VERSION 3.15)
project(blockch3)

set(CMAKE_CXX_STANDARD 14)

add_executable(blockch3 main.cpp Block/Block.h BlockChain/BlockChain.h Block/Block.cpp BlockChain/BlockChain.cpp
        hashFunction/helperHashFunctions.h hashFunction/helperHashFunctions.cpp hashFunction/hashFunction.cpp
        helperFunctions/helperFunctions.h helperFunctions/helperFunctions.cpp
        Transaction/Transaction.cpp User/User.cpp)