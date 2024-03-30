// this is the modification of the file provided 

#include "Finder.h"
using namespace std;

// // time complexity O(m(n*m)) -> O(n * m)
// // compared to the previous version this updated version does not look at parts of the string that will definetly not match
// vector<int> Finder::findSubstrings(string& s1, string& s2) {
//     // init result vector
//     vector<int> result;

//     // for loop for range 1->m s2
//     for (size_t i = 1; i <= s2.size(); i++) {
//         // get index of the substring occurance in s2
//         size_t found;
//         if (result.size() > 0){
//             found = s1.find(s2.substr(0, i), (size_t)result.back()); // o(n) opperation
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


// this is a far more efficient solution 
#include "Finder.h"
using namespace std;

#include <unordered_map>

// function time complexity is O(n + m) n = length of s1 and m = length of s2
vector<int> Finder::findSubstrings(string& s1, string& s2) {
    // n is the size of s1 and m is the size of s2
    // this was mainly so the Big O notation was easy to understand
    int n = s1.size(), m = s2.size();

    vector<int> pattern_index(m + 1, 0);

    // declare a scope (so that the last_occurence map doesnt sit in memory)
    {
        // create the pattern_index table O(m)
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

    // conduct the pattern matching algorithm and store the first time a new value of j is reached (create result)
    // time complexity O(n)

    int j = 0;
    for (int i = 0; i < n; i++){
        // find last character that matches the current text[i] value
        while (j > 0 && s1[i] != s2[j]){
            j = pattern_index[j];
        }

        // if there is a match 
        if (s1[i] == s2[j]){
            // check if this is the first time a match has been seen with this value of j
            if ((int)result.size() == j){
                // if it is the start of the matched patern to the result vector
                result.push_back(i - j);
            }
            // increment j
            j++;
        }
        // if j has reached the end of string s2
        if (j == m){
            // return the result vector (no -1 needed)
            return result;
            break;
        }
    }

    // if the pattern was not completely matched then add the -1 to indicate this
    result.push_back(-1);

    // return the result vector
    return result;
}

