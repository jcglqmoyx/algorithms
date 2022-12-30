#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        for (int i = 0; i < word.size(); i++) {
            int cnt[26] = {};
            for (int j = 0; j < word.size(); j++) {
                if (i == j) continue;
                cnt[word[j] - 'a']++;
            }
            int freq = -1;
            bool flag = true;
            for (int j: cnt) {
                if (j) {
                    if (freq == -1) freq = j;
                    else {
                        if (j != freq) {
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if (flag) return true;
        }
        return false;
    }
};