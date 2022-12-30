#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
        vector<int> res(k);
        unordered_map<int, unordered_set<int>> map;
        for (auto &log: logs) {
            map[log[0]].insert(log[1]);
        }
        for (auto &x: map) {
            res[x.second.size() - 1]++;
        }
        return res;
    }
};