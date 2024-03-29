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
    // init result vector
    vector<int> result;
    
    int n = s1.size(), m = s2.size();

    // complexity is O()
    int start_from = 0;
    for (int i = 1; i <= s2.size(); i++){
        string pattern = s2.substr(0, i);
        result.push_back(KMP(s1, pattern, start_from));
        if (result.back() == -1){
            break;
        } else {
            start_from = result.back();
        }
    }


    return result;
}

int Finder::KMP(string& text, string& pattern, int start = 0){
    vector<int> pattern_index(pattern.size() + 1, 0);

    unordered_map<char, int> last_occurrence;
    for (int i = 1; i <= pattern.size(); i++){
        if(last_occurrence.find(pattern[i - 1]) != last_occurrence.end()) {
            pattern_index[i] = last_occurrence[pattern[i - 1]];
        }
        last_occurrence[pattern[i - 1]] = i;
    }

    int j = 0;
    for (int i = start; i < text.size(); i++){
        // find last character than matches the current text[i] value
        while (j > 0 && text[i] != pattern[j]){
            j = pattern_index[j];
        }
        if (text[i] == pattern[j]){
            j++;
        }
        if (j == pattern.size()){
            return i - j + 1; // Returning the index of the first occurrence
        }
    }
    return -1; // Not found
}

