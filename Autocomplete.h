#ifndef AUTOCOMPLETE
#define AUTOCOMPLETE

#include <unordered_map>
#include <vector>
#include <string>

// basic TrieNode datastructure
class TrieNode {
public:
    char letter;

    bool endOfWord;

    std::unordered_map<char, TrieNode*> children;

    TrieNode(char letter);
};

// autocomplete classs
class Autocomplete {
private:
    TrieNode* start;

    // deconstructor helper function
    void deleteChildren(TrieNode* node);

    // sufix finder helper function (DFS)
    void suffixHelper(std::vector<std::string>& res, std::string word,TrieNode* node);

public:
    // constructor (innit start)
    Autocomplete();

    // deconstructor (calls deleteChildren)
    ~Autocomplete();

    // insert the word into the trie
    void insert(std::string word);
    
    // search for the word in the trie
    // return whether in trie and a pointer to the end of the word node (for autocomplete)
    std::pair<bool,TrieNode*> searchWord(std::string word);

    // get suggestions (suffixes)
    std::vector<std::string> getSuggestions(std::string partialWord);
};

#endif //AUTOCOMPLETE