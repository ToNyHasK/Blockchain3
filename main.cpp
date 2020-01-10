#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "Block/Block.h"
#include "BlockChain/BlockChain.h"
#include "helperFunctions/helperFunctions.h"
#include "User/User.h"


int main() {
    BlockChain blockChain = BlockChain();
    std::vector<User> users = generateUsers();
    std::vector<Transaction> mempool = generateTransactionPool(users);
    std::random_device rd;
    std::mt19937_64 gen(rd());
    int count = 0;
    while (mempool.size() >= 100) {
        std::vector<Block> candidates;
        std::uniform_int_distribution<> randomAmount(0, mempool.size()-1);
        // std::vector<int> are the indices (indexes) of transactions that are put in a candidate
        // theres a vector of vectors because 5 candidates all have separate (maybe overlapping) transactions with their own indices
        std::vector< std::vector<int> > indicesToDelete (5);
        for (int i = 0; i < 5; i++) {
            std::vector<Transaction> blockTransactions;
            for (int j = 0; j < 100; j++) {
                int index = randomAmount(gen);
                blockTransactions.push_back(mempool[index]);
                indicesToDelete[i].push_back(index);
            }
            Block candidateBlock = Block();
            candidateBlock.setTransactions(blockTransactions);
            candidates.push_back(candidateBlock);
        }
        //winnerIndex: index of the winning block in candidates
        int winnerIndex = mineBlocks(blockChain, candidates);
        std::cout << "Block nr. " << winnerIndex << " won. \nBlocks added to blockchain: " << count << "\n\n";
        std::vector<int> deletingIndices = indicesToDelete[winnerIndex];
        //need to be sorted to not delete an element that doesnt exist anymore
        std::sort(deletingIndices.begin(), deletingIndices.end(), std::greater<>());
        for (int i : deletingIndices) {
            mempool.erase(mempool.begin()+i);
        }
        count++;
    }
}