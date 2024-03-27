#include "Finder.h"
using namespace std;
vector<int> Finder::findSubstrings(string& s1, string& s2) {
    // init result vector
    // vector<int> result;

    // // for loop for range 1->n s1
    // for (size_t i = 1; i <= s2.size(); i++) {
    //     // get index of the substring occurance in s2
    //     size_t found = string::npos;
    //     if (result.size() > 0){
    //         found = s1.find(s2.substr(0, i), (size_t)result.back()); // o(len(s1)*len(s2)) opperation
    //     } else {
    //         found = s1.find(s2.substr(0, i)); // o(len(s1)*len(s2)) opperation
    //     }

    //     // if the substring is in s1
    //     if (found != string::npos) {
    //         // append the index to the result vector
    //         result.push_back(found);
    //     } else {
    //         // append -1 to the result vector
    //         result.push_back(-1);
    //         break;
    //     }
    // }
    // return result


    vector<int> result;
    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), 0));
    // o(len(s1) * len(s2)

    int n = s1.size(), m = s2.size();

    for (int i = 0; i < n; i++){
        if (s1[i] == s2[0]){
            dp[i][0] = 1;
            if ((int)result.size() < 1){
                result.push_back(i);
            }
        }
    }
    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            if (s1[i] == s2[j] && dp[i-1][j-1] > 0){
                dp[i][j] = dp[i-1][j-1] + 1;
                if ((int)result.size() < j+1){
                    result.push_back(i-dp[i][j]+1);
                }
            }
        }
    }
    result.push_back(-1);
    return result;
}
