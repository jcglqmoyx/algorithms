#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int> &arr) {
        vector<int> res;
        res.reserve(arr.size());
        vector<int> cp(arr);
        sort(cp.begin(), cp.end());
        unordered_map<int, int> map;
        int rank = 1;
        for (int x: cp) {
            if (!map[x]) {
                map[x] = rank++;
            }
        }
        for (int x: arr) {
            res.push_back(map[x]);
        }
        return res;
    }
};