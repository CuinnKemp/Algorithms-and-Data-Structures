#include "DocumentManager.h"

#include <bits/stdc++.h>
using namespace std;

int main(){
    DocumentManager d1;

    d1.addDocument("test", 1, 3);
    d1.addDocument("test2", 2, 3);
    d1.addPatron(1);

    int docID = d1.search("test");
    cout << docID << endl;
    cout << d1.borrowDocument(docID, 1) << endl;
}