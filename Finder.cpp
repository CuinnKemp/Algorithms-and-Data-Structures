#include "Finder.h"
using namespace std;
vector<int> Finder::findSubstrings(string& s1, string& s2) {
    // init result vector
    vector<int> result;

    // for loop for range 1->n s1
    for (size_t i = 1; i <= s2.size(); i++) {
        // get index of the substring occurance in s2
        size_t found = string::npos;
        if (result.size() > 0){
            found = s1.find(s2.substr(0, i), (size_t)result.back()); // o(len(s1)*len(s2)) opperation
        } else {
            found = s1.find(s2.substr(0, i)); // o(len(s1)*len(s2)) opperation
        }

        // if the substring is in s1
        if (found != string::npos) {
            // append the index to the result vector
            result.push_back(found);
        } else {
            // append -1 to the result vector
            result.push_back(-1);
            break;
        }
    }
    return result;
}
