#include "Block.h"
#include "../merkle/merkleHash.h"

Block::Block(std::string prevBlockHash)
        : prevBlockHash(std::move(prevBlockHash)) {
    timeStamp = time(nullptr);
}

Block::Block() {
    timeStamp = time(nullptr);
};

void Block::setTransactions(const std::vector<Transaction> &transactions) {
    this->transactions = transactions;
    std::vector<std::string> transactionIDs;
    transactionIDs.reserve(transactions.size());
for (const auto & transaction : transactions) {
        transactionIDs.push_back(transaction.ID);
    }
    merkelRootHash = create_merkle(transactionIDs);
}

