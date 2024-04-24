#include <iostream>

#include "LinkedList.h"


int main(){
    int arr[] = {1,2,3,4,5,6};

    LinkedList list(arr, 6);

    list.printList();
    std::cout << list.get(6) << std::endl;
    
}