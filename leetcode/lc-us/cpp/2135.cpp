#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords) {
        unordered_set<int> set;
        for (auto &s: startWords) {
            int mask = 0;
            for (char c: s) mask |= 1 << (c - 'a');
            set.insert(mask);
        }
        int cnt = 0;
        for (auto &s: targetWords) {
            int mask = 0;
            for (char c: s) mask |= 1 << (c - 'a');
            for (int i = 0; i < 26; i++) {
                if (mask >> i & 1) {
                    int t = mask ^ (1 << i);
                    if (set.count(t)) {
                        cnt++;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};