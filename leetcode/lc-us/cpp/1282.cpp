#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < groupSizes.size(); i++) {
            if (map.count(groupSizes[i])) {
                map[groupSizes[i]].push_back(i);
            } else {
                vector<int> arr = {i};
                map[groupSizes[i]] = arr;
            }
            if (map[groupSizes[i]].size() == groupSizes[i]) {
                res.push_back(map[groupSizes[i]]);
                vector<int> arr;
                map[groupSizes[i]] = arr;
            }
        }
        return res;
    }
};