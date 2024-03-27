#include "Finder.h"

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1 = "111111", s2 = "2324";
    Finder f1;
    vector<int> res = f1.findSubstrings(s1, s2);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
}

