#include "LinkedList.h"

#include <iostream>
#include <climits>

LinkedList::LinkedList(){
    this->head = nullptr;
    this->length = 0;
}
    
LinkedList::LinkedList(int* array, int len){
    this->head = nullptr;
    this->length = 0;

    // insert array backwards to front of list to reduce complexity
    for (int i = len-1; i > -1; i--){
        this->insertStart(array[i]);
    }
}

LinkedList::~LinkedList(){
    Node* pointer = head;

    while (pointer != nullptr){
        Node* temp = pointer->get_link();
        delete pointer;
        pointer = temp;
    }
}

void LinkedList::insertStart(int newNum){
    Node* temp = new Node(newNum, this->head);
    this->head = temp;
    this->length++;
    return;
}

void LinkedList::insertEnd(int newNum){
    if (length == 0 || head == nullptr){
        length = 0;
        insertStart(newNum);
        return;
    }

    Node* pointer = head;
    
    while (pointer->get_link() != nullptr){
        pointer = pointer->get_link();
    }

    Node* temp = new Node(newNum, nullptr);
    pointer->set_link(temp);

    length++;
    return;
}

void LinkedList::insertPosition(int pos, int newNum){
    if (pos <= 1 || this->head == nullptr || length == 0){
        insertStart(newNum);
        return;
    } else if (pos > length){
        insertEnd(newNum);
        return;
    }

    Node* pointer = head;
    int counter = 1;
    while (counter < pos-1 && pointer->get_link() != nullptr){
        pointer = pointer->get_link();
        counter++;
    }

    Node* temp = new Node(newNum, pointer->get_link());
    pointer->set_link(temp);
    
    length++;
    return;
}

bool LinkedList::deletePosition(int pos){
    if (pos < 1 || pos > length ) return false;
    if (pos == 1){
        Node* temp = this->head;
        this->head = this->head->get_link();
        delete temp;
        this->length--;
        return true;
    }

    Node* pointer = head;
    int counter = 1;
    while (counter < pos-1 && pointer->get_link() != nullptr){
        pointer = pointer->get_link();
        counter++;
    }
    Node* temp = pointer->get_link();
    pointer->set_link(temp->get_link());
    delete temp;

    length--;
    return true;


}

int LinkedList::get(int pos){
    if (pos < 1 || pos > this->length){
        return INT_MAX;
    }

    Node* pointer = head;
    for (int i = 1; i < pos; i++){
        pointer = pointer->get_link();
    }
    return pointer->get_data();
}

int LinkedList::search(int target){
    Node* pointer = head;
    int counter = 1;
    while (pointer != nullptr){
        if (pointer->get_data() == target){
            return counter;
        }
        counter++;
        pointer = pointer->get_link();
    }

    return -1;
}

void LinkedList::printList(){
    std::cout << "[";
    Node* pointer = head;
    std::cout << pointer->get_data();
    pointer = pointer->get_link();
    while (pointer != nullptr){
        std::cout << " " << pointer->get_data();
        pointer = pointer->get_link();
    }
    std::cout << "]" << std::endl;
}