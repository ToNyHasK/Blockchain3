cmake_minimum_required(VERSION 3.15)
project(blockch3)

set(CMAKE_CXX_STANDARD 14)

add_executable(blockch3 main.cpp Blockas/Block.h BlockChain/BlockChain.h Blockas/Block.cpp BlockChain/BlockChain.cpp Hash/helperHashFunctions.h Hash/helperHashFunctions.cpp Hash/hashFunction.cpp HelpFunc/helperFunctions.h HelpFunc/helperFunctions.cpp Transaction/Transaction.cpp Transaction/Transaction.h User/User.cpp User/User.h merkle/merkleHash.cpp merkle/merkleHash.h)