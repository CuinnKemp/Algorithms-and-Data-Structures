#include <bits/stdc++.h>
using namespace std;

#include "Autocomplete.h"

#include "PrefixMatcher.h"

int main() {
    Autocomplete t1;

    t1.insert("hello");
    t1.insert("he");
    t1.insert("hell");
    t1.insert("heap");
    t1.insert("hate");

    auto temp = t1.getSuggestions("hel");

    for (auto v : temp){
        cout << v << endl;
    }


    PrefixMatcher p1;

    p1.insert("1100110111", 1);
    p1.insert("110011011", 2);
    p1.insert("11001101", 3);

    cout << p1.selectRouter("1100110111") << endl;
    cout << p1.selectRouter("110011011") << endl;
    cout << p1.selectRouter("11001101") << endl;
    cout << p1.selectRouter("1") << endl;

    
}