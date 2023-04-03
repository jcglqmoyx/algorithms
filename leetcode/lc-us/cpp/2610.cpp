#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int> &nums) {
        unordered_map<int, int> cnt;
        for (int x: nums) cnt[x]++;
        vector<vector<int>> res;
        while (true) {
            vector<int> vec;
            vector<int> del;
            for (auto &[k, v]: cnt) {
                vec.push_back(k);
                if (v == 1) del.push_back(k);
                cnt[k]--;
            }
            res.push_back(vec);
            for (int x: del) cnt.erase(x);
            if (cnt.empty()) break;
        }
        return res;
    }
};