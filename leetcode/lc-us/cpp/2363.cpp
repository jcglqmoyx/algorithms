#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2) {
        unordered_map<int, int> map;
        for (auto &item: items1) {
            map[item[0]] = item[1];
        }
        for (auto &item: items2) {
            map[item[0]] += item[1];
        }
        vector<vector<int>> res;
        res.reserve(map.size());
        for (auto[k, v]: map) {
            res.push_back({k, v});
        }
        sort(res.begin(), res.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });
        return res;
    }
};