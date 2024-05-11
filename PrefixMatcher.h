#ifndef PREFIXMATCHER
#define PREFIXMATCHER


#include <unordered_map>
#include <vector>
#include <string>

class RouterNode {
public:
    char letter;

    int routerNumber = -1;

    std::unordered_map<char, RouterNode*> children;

    RouterNode(char letter);
};

class PrefixMatcher {
private:
    RouterNode* start;

    void deleteChildren(RouterNode* node);

public:
    PrefixMatcher();

    ~PrefixMatcher();

    void insert(std::string address, int routerNumber);
    
    int selectRouter(std::string networkAddress);

};

#endif //PREFIXMATCHER