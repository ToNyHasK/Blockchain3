#include <random>
#include <algorithm>
#include <iostream>
#include "helperFunctions.h"

std::string createNumberString(const int number, const int length) {
    std::string string;
    for (int i = 0; i < length; i++) {
        string += std::to_string(number);
    }
    return string;

}
//bloko header hash skaiciavimas
std::string calculateHash(const Block &block) {
    std::stringstream ss;
    ss << block.prevBlockHash << block.timeStamp << block.version << block.nonce << block.difficultyTarget;
    return hashFunc(ss.str());
}

//bloku kasimas ir dejimas i chain (vienas blogas per funkcijos apsisukima). Pilnas algoritmas maine + sitas
int mineBlocks(BlockChain &blockChain, const std::vector<Block> &candidates) {
    std::vector<int> indexes;
    indexes.reserve(candidates.size());
    for (int i = 0; i < candidates.size(); i++) {
        indexes.push_back(i);
    }
    std::shuffle(indexes.begin(), indexes.end(), std::mt19937_64(std::random_device()()));
    bool done = false;
    int initialHashCeiling = HASH_INCREASE;
    Block block = blockChain.getLastBlock();
    // bloku varzymasis
    while (true) {
        std::string hashedBlock;
        int hashCount = 0;
        for (int i = 0; i < candidates.size(); i++) {
            int in = indexes[i];

            while (hashCount < initialHashCeiling) {

                hashedBlock = calculateHash(block);
                if (hashedBlock.substr(0, block.difficultyTarget) == createNumberString(1, block.difficultyTarget)) {
                    done = true;
                } else {
                    block.nonce += 1;
                    hashCount++;
                }
                if (done) {
                    blockChain.addBlock(hashedBlock);
                    return in;
                }

            }
        }
    }
}



