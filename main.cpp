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
    Heap<int> h1({3,4,5});
    
    print(h1);
    cout << h1.getMin() << endl;

    h1.remove(3);
    h1.remove(5);

    cout << h1.getMin() << endl;

    
}