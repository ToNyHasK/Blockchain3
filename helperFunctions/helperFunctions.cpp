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
    std::shuffle(indexes.begin(), indexes.end(), std::mt19937(std::random_device()()));
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
                //std::cout<< "indexas: " << in <<"\n";
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

//users generavimas
std::vector<User> generateUsers() {
    std::vector<User> users;
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<> randomAmount(100, 1000000);
    for (int i = 0; i < USER_COUNT; i++) {
        int random = randomAmount(gen);
        std::string name = "Petras " + std::to_string(i);
        users.emplace_back(name, hashFunc(name), random);
    }
    return users;
}

//ID gavimas
std::string hashTransaction(const Transaction &transaction) {
    std::stringstream ss;
    ss << transaction.version << transaction.from << transaction.to;
    return hashFunc(ss.str());
}

// Patikrina ar transakcija galima
void checkTransactions(std::vector<Transaction> &transactions, const std::vector<User> users) {
    for (int i = 0; i < transactions.size(); i++) {
        std::string user = transactions[i].from;
        // vartotojo, (siuntejo) pagal public_key radimas
        auto foundUser = std::find_if(users.begin(), users.end(),
                                      [&user](const User &obj) { return obj.public_key == user; });
        if (foundUser != users.end()) {
            //balanso tikrinimas
            if ((*foundUser).DisneyCoin < transactions[i].amount) {
                transactions.erase(transactions.begin() + i);
                continue;
            }
        }
        //transakcijos hash'o tikrinimas
        if (hashTransaction(transactions[i]) != transactions[i].ID) {
            transactions.erase(transactions.begin() + i);
        }
    }
}

std::vector<Transaction> generateTransactionPool(const std::vector<User> &users) {
    std::vector<Transaction> mempool;
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<> randomUsers(0, users.size()-1);
    std::uniform_int_distribution<> randomAmount(100, 1000000);
    for (int i = 0; i < TRANSACTION_AMOUNT; i++) {
        Transaction transaction = Transaction(
                users[static_cast<int>(randomUsers(gen))].public_key,
                users[static_cast<int>(randomUsers(gen))].public_key,
                static_cast<int>(randomAmount(gen)));
        transaction.ID = hashTransaction(transaction);
        mempool.push_back(transaction);
    }
    checkTransactions(mempool, users);
    return mempool;
}




