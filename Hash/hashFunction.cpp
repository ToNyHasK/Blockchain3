#include <string>
#include <ios>
#include <iostream>
#include <sstream>

std::string hashFunc(std::string text) {
    unsigned int sum = 2;
    if (text == "") {
        text += std::to_string(sum);
    }
    for (auto i : text) {
        unsigned int val = int(i);
        sum += val * val;
        sum += (~val % ~sum);
        sum +=  sum << 1;
        sum %= (sum & val) - (val + 13) * (val / 2);
    }
    sum = sum >> 1;
    std::stringstream ss;
    ss << std::hex << sum;
    std::string rez = (ss.str());
    while (rez.length() != 20) {
        for (unsigned int ch : rez) {
            ch = (ch +~ rez.length()) * sum >> 2;
            ch += sum | ch;
            ch += ch >> 2;
            ss.str("");
            ss << std::hex << ch;
            rez += ss.str();
        }
        if (rez.length() > 20) {
            rez = rez.substr(0, 20);
        }
    }
    return rez;
}


