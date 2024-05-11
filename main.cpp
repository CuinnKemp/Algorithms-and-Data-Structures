#include <bits/stdc++.h>
using namespace std;

#include "Autocomplete.h"

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
}