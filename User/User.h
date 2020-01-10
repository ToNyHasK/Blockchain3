#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(std::string name, std::string  public_key, int DisneyCoin);
    std::string name;
    std::string public_key;
    int DisneyCoin;
};

#endif // USER_H
