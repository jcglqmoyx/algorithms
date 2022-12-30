#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>> &arrays) {
        int cnt[101] = {101};
        for (auto &row: arrays) {
            for (int x: row) {
                cnt[x]++;
            }
        }
        vector<int> res;
        for (int i = 1; i <= 100; i++) {
            if (cnt[i] == arrays.size()) {
                res.push_back(i);
            }
        }
        return res;
    }
};