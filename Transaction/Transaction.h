#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "../User/User.h"
#include <string>

class Transaction {
public:
    Transaction(const std::string &from, const std::string &to, int amount);
    std::string from;
    std::string to;
    int version = 1;
    int amount;
    std::string ID;
};

#endif
