#include "Autocomplete.h"

TrieNode::TrieNode(char letter){
    this->letter = letter;
}

Autocomplete::Autocomplete(){
    this->start = new TrieNode(' ');
}

Autocomplete::~Autocomplete(){
    deleteChildren(this->start);
}

void Autocomplete::deleteChildren(TrieNode* node){
    for (auto child : node->children){
        deleteChildren(child.second);
    }
    delete node;
}

void Autocomplete::insert(std::string word){
    TrieNode* curNode = start;
    for (int i = 0; i < (int)word.length(); i++){
        if (curNode->children[word[i]] == nullptr){
            curNode->children[word[i]] = new TrieNode(word[i]);
        }
        curNode = curNode->children[word[i]];
    }
    curNode->endOfWord = true;
}

std::pair<bool,TrieNode*> Autocomplete::searchWord(std::string word){
    TrieNode* curNode = start;
    for (int i = 0; i < (int)word.length(); i++){
        if (curNode->children[word[i]] == nullptr){
            return {false,nullptr};
        }
        curNode = curNode->children[word[i]];
    }
    if (curNode->endOfWord == true){
        return {true, curNode};
    }
    
    return {false, curNode};
}

void Autocomplete::suffixHelper(std::vector<std::string>& res, std::string word, TrieNode* node){
    word += node->letter;
    if (node->endOfWord){
        res.push_back(word);
    }


    for (auto pair : node->children){
        suffixHelper(res, word, pair.second);
    }
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord){
    std::vector<std::string> words;

    auto endOfWord = searchWord(partialWord);
    
    // the word is a full word and should be added to the list
    if (endOfWord.first){
        words.push_back(partialWord);
    }

    // the word is either not in the list 
    if (endOfWord.second == nullptr){
        return words;
    }
    
    for (auto pair : endOfWord.second->children){
        suffixHelper(words, partialWord, pair.second);
    }

    return words;
}

