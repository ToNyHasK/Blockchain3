#include "Transaction.h"

Transaction::Transaction(const std::string &from, const std::string &to, const int amount)
        : from(from), to(to), amount(amount) {}
