#include <iostream>

#include "LinkedList.h"


int main(){
    int arr[] = {1,2,3,4,5,6};

    LinkedList list(arr, 6);

    list.insertPosition(1, 100);

    list.printList();
    
    std::cout << list.search(100) << std::endl;

    std::cout << list.get(5) << std::endl;
}