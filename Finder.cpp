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

#include <unordered_map>

vector<int> Finder::findSubstrings(string& s1, string& s2) {
    int n = s1.size(), m = s2.size();

    vector<int> pattern_index(m + 1, 0);

    {
    unordered_map<char, int> last_occurrence;
    for (int i = 1; i <= m; i++){
        if(last_occurrence.find(s2[i - 1]) != last_occurrence.end()) {
            pattern_index[i] = last_occurrence[s2[i - 1]];
        }
        last_occurrence[s2[i - 1]] = i;
    }
    }

    // init result vector
    vector<int> result;

    int j = 0;
    for (int i = 0; i < s1.size(); i++){
        // find last character than matches the current text[i] value
        while (j > 0 && s1[i] != s2[j]){
            j = pattern_index[j];
        }
        if (s1[i] == s2[j]){
            if (result.size() == j){
                result.push_back(i - j);
            }
            j++;
        }
        if (j == s2.size()){
            break; // Returning the index of the first occurrence
        }
    }
    if (result.size() != s2.size()){
        result.push_back(-1);
    }
    return result;
}

