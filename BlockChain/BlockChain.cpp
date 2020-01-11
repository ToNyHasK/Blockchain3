#include "BlockChain.h"

#include <utility>
#include "../Hash/hashFunction.h"
#include "../Blockas/Block.h"
#include "../HelpFunc/helperFunctions.h"

BlockChain::BlockChain() {
    chain.emplace_back(hashFunc("Žalgris pralaimėjo aštuntą kartą iš eilės 2019-12-19"));
}

void BlockChain::addBlock(std::string hash) {
    Block block = Block(std::move(hash));
    this->chain.emplace_back(block);
}

Block BlockChain::getLastBlock() const {
    return this->chain.back();
}

