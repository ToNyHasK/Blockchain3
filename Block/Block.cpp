#include "Block.h"

Block::Block(std::string prevBlockHash)
        : prevBlockHash(std::move(prevBlockHash)) {
    timeStamp = time(nullptr);
}

Block::Block() {
    timeStamp = time(nullptr);
};

