#include "PrefixMatcher.h"

RouterNode::RouterNode(char letter){
    this->letter = letter;
}

PrefixMatcher::PrefixMatcher(){
    this->start = new RouterNode(' ');
}

PrefixMatcher::~PrefixMatcher(){
    deleteChildren(start);
}

void PrefixMatcher::deleteChildren(RouterNode* node){
    for (auto child : node->children){
        deleteChildren(child.second);
    }
    delete node;
}

void PrefixMatcher::insert(std::string address, int routerNumber){
    RouterNode* curNode = start;
    for (int i = 0; i < (int)address.length(); i++){
        if (curNode->children[address[i]] == nullptr){
            curNode->children[address[i]] = new RouterNode(address[i]);
        }
        curNode = curNode->children[address[i]];
    }
    curNode->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(std::string networkAddress){
    int bestResult = -1;
    RouterNode* curNode = start;
    if (curNode->routerNumber != -1) bestResult = curNode->routerNumber;
    for (int i = 0; i < (int)networkAddress.length(); i++){
        if (curNode->children[networkAddress[i]] == nullptr){
            return bestResult;
        }
        curNode = curNode->children[networkAddress[i]];
        if (curNode->routerNumber != -1) bestResult = curNode->routerNumber;
    }
    
    return bestResult;
}
