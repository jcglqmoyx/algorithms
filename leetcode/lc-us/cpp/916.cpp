#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string> &A, vector<string> &B) {
        vector<string> subsets;
        int count[26] = {0};
        for (const string &word: B) {
            int temp[26] = {0};
            for (char c: word) temp[c - 'a']++;
            for (int i = 0; i < 26; i++) count[i] = max(count[i], temp[i]);
        }
        for (const string &word: A) {
            int temp[26] = {0};
            for (char c: word) temp[c - 'a']++;
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (temp[i] < count[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) subsets.emplace_back(word);
        }
        return subsets;
    }
};