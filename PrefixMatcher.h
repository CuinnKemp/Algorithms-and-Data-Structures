#ifndef PREFIXMATCHER
#define PREFIXMATCHER


#include <unordered_map>
#include <vector>
#include <string>

// basic TrieNode but rather than isEnd var we have routerNum (default -1)
class RouterNode {
public:
    char letter;

    int routerNumber = -1;

    // in this situation we could use a vector of 2 elements
    // chose not to cause there was no explicit statement that the values must be 0/1
    std::unordered_map<char, RouterNode*> children;

    // constructor
    RouterNode(char letter);
};

class PrefixMatcher {
private:
    // hold the head of the Trie
    RouterNode* start;

    // desends into Trie and frees the memory of each allocated node (on asent)
    void deleteChildren(RouterNode* node);

public:
    // constructor (innit start var)
    PrefixMatcher();

    // destructor (calls deleteChildren on start);
    ~PrefixMatcher();

    // insert address and assign a routerNumber
    void insert(std::string address, int routerNumber);
    
    // select the router with the longest prefix
    int selectRouter(std::string networkAddress);
};

#endif //PREFIXMATCHER