#include "User.h"

#include <utility>

User::User(const std::string name, std::string  public_key, const int DisneyCoin)
        : name(name), public_key(std::move(public_key)), DisneyCoin(DisneyCoin) {}
