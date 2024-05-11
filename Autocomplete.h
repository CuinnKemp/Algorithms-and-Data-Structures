#ifndef AUTOCOMPLETE
#define AUTOCOMPLETE

#include <unordered_map>
#include <vector>
#include <string>

class TrieNode {
public:
    char letter;

    bool endOfWord;

    std::unordered_map<char, TrieNode*> children;

    TrieNode(char letter);
};

class Autocomplete {
private:
    TrieNode* start;

    void deleteChildren(TrieNode* node);

    void suffixHelper(std::vector<std::string>& res, std::string word,TrieNode* node);

public:
    Autocomplete();

    ~Autocomplete();

    void insert(std::string word);
    
    std::pair<bool,TrieNode*> searchWord(std::string word);

    std::vector<std::string> getSuggestions(std::string partialWord);
};

#endif //AUTOCOMPLETE