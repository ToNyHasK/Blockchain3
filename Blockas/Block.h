#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include <string>
#include <ctime>
#include <vector>
#include <sstream>
#include <utility>
#include "../Hash/hashFunction.h"
#include "../Transaction/Transaction.h"

class Block {

public:

    explicit Block(std::string prevBlockHash);
    Block();

    std::string prevBlockHash;
    std::time_t timeStamp{};
     int version = 1;
    std::string merkelRootHash;
    long long int nonce = 1;
     int difficultyTarget = 1;

    void setTransactions(const std::vector<Transaction> &transactions);

private:
    std::vector<Transaction> transactions;


};

#endif //BLOCKCHAIN_BLOCK_H
