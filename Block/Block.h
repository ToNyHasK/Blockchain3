#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include <string>
#include <ctime>
#include <vector>
#include <sstream>
#include <utility>
#include "../hashFunction/hashFunction.h"

class Block {

public:

    explicit Block(std::string prevBlockHash);
    Block();

    std::string prevBlockHash;
    std::time_t timeStamp{};
     int version = 1;
    long long int nonce = 1;
     int difficultyTarget = 1;

};

#endif //BLOCKCHAIN_BLOCK_H