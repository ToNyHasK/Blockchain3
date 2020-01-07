#ifndef BLOCKCHAIN_HELPERFUNCTIONS_H
#define BLOCKCHAIN_HELPERFUNCTIONS_H

#include <string>
#include <vector>
#include "../BlockChain/BlockChain.h"

const int USER_COUNT = 3500;
const int TRANSACTION_AMOUNT = 20000;
const int HASH_INCREASE = 1000;

std::string createNumberString(const int number, const int length);
std::string calculateHash(const Block &block);
int mineBlocks(BlockChain &blockChain, const std::vector<Block> &candidates);

#endif //BLOCKCHAIN_HELPERFUNCTIONS_H
