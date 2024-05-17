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
    Heap<int> h1({10,9,8,7,6,5,4,3,2});

    print(h1);
    cout << h1.getMin() << endl;
    h1.insert(-1);
    print(h1);
    cout << h1.getMin() << endl;
    print(h1);
    h1.remove(-1);
    print(h1);
    cout << h1.getMin() << endl;

    h1.remove(8);
    print(h1);
    cout << h1.getMin() << endl;
}