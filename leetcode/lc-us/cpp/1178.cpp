#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles) {
        unordered_map<int, int> cnt;

        for (auto &word: words) {
            int mask = 0;
            for (char c: word) {
                mask |= 1 << (c - 'a');
            }
            if (__builtin_popcount(mask) <= 7) {
                cnt[mask]++;
            }
        }
        vector<int> res(puzzles.size());
        for (int i = 0; i < res.size(); i++) {
            auto &p = puzzles[i];
            int mask = 0;
            for (char c: p) {
                mask |= 1 << (c - 'a');
            }
            int required = 1 << (p[0] - 'a');
            for (int j = mask; j; j = (j - 1) & mask) {
                if (j & required) {
                    res[i] += cnt[j];
                }
            }
        }
        return res;
    }
};