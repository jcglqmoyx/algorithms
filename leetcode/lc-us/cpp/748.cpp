#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        string res;
        int count[26] = {};
        for (char c: licensePlate) {
            if (isalpha(c)) {
                count[tolower(c) - 'a']++;
            }
        }
        for (const string &word: words) {
            int temp_count[26] = {};
            for (char c: word) {
                if (isalpha(c)) {
                    temp_count[tolower(c) - 'a']++;
                }
            }
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (temp_count[i] < count[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (res.empty() || word.size() < res.size()) {
                    res = word;
                }
            }
        }
        return res;
    }
};