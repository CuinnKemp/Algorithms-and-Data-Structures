#include "PrefixMatcher.h"

// constructor for RouterNode (the TrieNode)
RouterNode::RouterNode(char letter){
    this->letter = letter;
}

// constructor for the Prefix matcher
PrefixMatcher::PrefixMatcher(){
    // init the start var
    this->start = new RouterNode(' ');
}

// destructor for prefix matcher
PrefixMatcher::~PrefixMatcher(){
    // calls the recursive memeory free method
    deleteChildren(start);
}

// free the memory of the Trie
void PrefixMatcher::deleteChildren(RouterNode* node){
    for (auto child : node->children){
        deleteChildren(child.second);
    }
    delete node;
}

// insert the address into the trie and allocate a router num
void PrefixMatcher::insert(std::string address, int routerNumber){
    // init a curNode var to move through the trie
    RouterNode* curNode = start;

    // go through each char in the address string
    for (int i = 0; i < (int)address.length(); i++){
        // if the char is not a child of the current node make add it to be
        if (curNode->children[address[i]] == nullptr){
            curNode->children[address[i]] = new RouterNode(address[i]);
        }

        // move to the next letter
        curNode = curNode->children[address[i]];
    }
    // at the end set the curNode router num to the provided val
    curNode->routerNumber = routerNumber;
}


// select the router from the Trie
int PrefixMatcher::selectRouter(std::string networkAddress){
    // set the bestResult to the default value
    int bestResult = -1;
    
    // innit the itterator var
    RouterNode* curNode = start;
    
    // go through the trie
    for (int i = 0; i < (int)networkAddress.length(); i++){
        // if the char is not a child of the current node then the longest prefix has been reached
        if (curNode->children[networkAddress[i]] == nullptr){
            // return the bestResult
            return bestResult;
        }
        // otherwise access this child and progress through the trie
        curNode = curNode->children[networkAddress[i]];

        // if the routerNum is not -1 then it is a valid router
        // update the bestResult var to hold this new longer prefix router
        if (curNode->routerNumber != -1) bestResult = curNode->routerNumber;
    }
    
    // if the entire address has been matched return the best result
    return bestResult; // if it is a perfect match the value will already be set as such
}
