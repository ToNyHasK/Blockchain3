#include <fstream>
#include <iostream>
#include "hashFunction.h"

bool checkStream(const std::ifstream& file) {
    // Check if you can open the file
    if (!file.is_open()) {
        std::cout << "Error while opening a file" << std::endl;
        return false;
    }
    return true;
}

void read(std::string &text, char *string) {
    std::ifstream file(string);
    bool hasFileBeenRead = false;
    if (!checkStream(file)) {
        hashFunc(string);
    } else {
        while (std::getline(file, text)) {
            std::cout << text << '\n';
            hasFileBeenRead = true;
            hashFunc(text);
        }
        if (!hasFileBeenRead) {
            hashFunc("");
        }
    }
}
