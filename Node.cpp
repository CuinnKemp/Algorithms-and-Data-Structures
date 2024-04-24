#include "Node.h"

Node::Node(int value = 0, Node* link = nullptr){
    this->data = value;
    this->link = link;
}

int Node::get_data(){
    return this->data;
}

void Node::set_data(int value){
    this->data = value;
}

Node* Node::get_link(){
    return this->link;
}

void Node::set_link(Node* link){
    this->link = link;
}