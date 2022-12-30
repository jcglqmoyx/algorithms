#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        vector<vector<int>> res(2);
        unordered_set<int> S;
        unordered_map<int, int> M;
        for (auto &m: matches) {
            int x = m[0], y = m[1];
            S.insert(x), S.insert(y);
            M[y]++;
        }
        for (int x: S) {
            if (!M.count(x)) res[0].push_back(x);
            else if (M[x] == 1) res[1].push_back(x);
        }
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res;
    }
};