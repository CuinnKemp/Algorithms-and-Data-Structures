// #include "Finder.h"
// using namespace std;
// vector<int> Finder::findSubstrings(string& s1, string& s2) {
//     // init result vector
//     vector<int> result;

//     // for loop for range 1->n s1
//     for (size_t i = 1; i <= s2.size(); i++) {
//         // get index of the substring occurance in s2
//         size_t found = string::npos;
//         if (result.size() > 0){
//             found = s1.find(s2.substr(0, i), (size_t)result.back()); // o(len(s1)*len(s2)) opperation
//         } else {
//             found = s1.find(s2.substr(0, i)); // o(len(s1)*len(s2)) opperation
//         }

//         // if the substring is in s1
//         if (found != string::npos) {
//             // append the index to the result vector
//             result.push_back(found);
//         } else {
//             // append -1 to the result vector
//             result.push_back(-1);
//             break;
//         }
//     }
//     return result;
// }


#include "Finder.h"
using namespace std;
vector<int> Finder::findSubstrings(string& s1, string& s2) {
    // init result vector
    vector<int> result;

    // O(n * m)
    for (int i = 0; i < s1.size(); i++){
        // initialise vars
        int s1Index = i, s2Index = 0;
        
        // while loop for while both counters are within range
        while(s1Index < (int)s1.size() &&  s2Index < (int)s2.size()){
            // if the indicies match then continue
            if (s1[s1Index] == s2[s2Index]){
                if (s1Index - i == result.size()){
                    result.push_back(i);
                }
                s1Index++;
                s2Index++;

            // otherwise break
            } else {
                break;
            }
        }
    }

    if (result.size() < s2.size()){
        result.push_back(-1);
    }

    return result;
}

