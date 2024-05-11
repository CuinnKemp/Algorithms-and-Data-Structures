#include "Autocomplete.h"

// TrieNode constructor
TrieNode::TrieNode(char letter){
    this->letter = letter;
}

// autocomp constructor
Autocomplete::Autocomplete(){
    this->start = new TrieNode(' ');
}

// autocomp destructor
Autocomplete::~Autocomplete(){
    // call delete children on start
    deleteChildren(this->start);
}

// free dat memory boi
void Autocomplete::deleteChildren(TrieNode* node){
    for (auto child : node->children){
        deleteChildren(child.second);
    }
    delete node;
}

// insert the word into the Trie
void Autocomplete::insert(std::string word){
    // init traverse var
    TrieNode* curNode = start;
    // itterate through word chars
    for (int i = 0; i < (int)word.length(); i++){
        // if the char is not a child
        if (curNode->children[word[i]] == nullptr){
            // add a child 
            curNode->children[word[i]] = new TrieNode(word[i]);
        }
        // access the char (word[i]) child from the current node
        curNode = curNode->children[word[i]];
    }
    // set the node val to be the end of the word
    curNode->endOfWord = true;
}

// search if the word is in the trie
std::pair<bool,TrieNode*> Autocomplete::searchWord(std::string word){
    // innit traverse var
    TrieNode* curNode = start;
    
    // iterate through word chars
    for (int i = 0; i < (int)word.length(); i++){
        // if the char is not a child of the node
        if (curNode->children[word[i]] == nullptr){
            // the word is not in the trie return false and a nullptr
            return {false,nullptr};
        }
        // access the word[i] child of the current node
        curNode = curNode->children[word[i]];
    }

    // if the current node is an end of word
    if (curNode->endOfWord == true){
        // return true and a pointer to this node
        return {true, curNode};
    }
    
    // return false (not end of word) and the pointe rto this node
    return {false, curNode};
}

// suffix helper function
void Autocomplete::suffixHelper(std::vector<std::string>& res, std::string word, TrieNode* node){
    // add the current letter to the word
    word += node->letter;
    // if the current node is the end of a word
    if (node->endOfWord){
        // push back this valid word
        res.push_back(word);
    }

    // itterate through all the children of the current node
    for (auto pair : node->children){
        // recursively call this function on the new nodes
        suffixHelper(res, word, pair.second);
    }
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord){
    // innit the result vector
    std::vector<std::string> words;

    // get the pair endOfWord from the search word method
    auto endOfWord = searchWord(partialWord);
    
    // the word is a full word and should be added to the list
    if (endOfWord.first){
        words.push_back(partialWord);
    }

    // the word is either not in the list 
    if (endOfWord.second == nullptr){
        return words;
    }
    
    // itterate throught the children of the node and get the valid words
    for (auto pair : endOfWord.second->children){
        suffixHelper(words, partialWord, pair.second);
    }

    // return these words
    return words;
}

