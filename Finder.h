#ifndef FINDER_H
#define FINDER_H
#include <chrono>
#include <iostream>
#include <string>
#include <vector>
class Finder {
private:
    int KMP(std::string& text, std::string& pattern, int start);
public:
    std::vector<int> findSubstrings(std::string& s1, std::string& s2);
};
#endif
