#include "Heap.tpp"


#include <bits/stdc++.h>
using namespace std;


void print(Heap<int> h1){
    for (auto i : h1.values){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    Heap<int> h1({1,2,3,4,5,6,7,8,9,10});
    
    print(h1);
    cout << h1.getMin() << endl;


    cout << h1.getMin() << endl;

    
}