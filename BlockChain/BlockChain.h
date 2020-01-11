#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H

#include <vector>
#include "../Blockas/Block.h"

class BlockChain {
public:
    BlockChain();

    void addBlock(std::string hash);
    Block getLastBlock() const;
private:
    std::vector<Block> chain;
};

#endif //BLOCKCHAIN_BLOCKCHAIN_H
