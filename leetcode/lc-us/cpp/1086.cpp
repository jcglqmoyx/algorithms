#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>> &items) {
        unordered_map<int, priority_queue<int>> map;
        for (const vector<int> &item: items) {
            map[item[0]].push(item[1]);
        }
        vector<vector<int>> res;
        for (auto &x: map) {
            int sum = 0;
            for (int i = 0; i < 5; i++) {
                sum += x.second.top();
                x.second.pop();
            }
            res.push_back({x.first, sum / 5});
        }
        sort(res.begin(), res.end());
        return res;
    }
};