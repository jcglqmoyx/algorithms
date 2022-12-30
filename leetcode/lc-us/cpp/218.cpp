#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        vector<vector<int>> res;
        vector<pair<int, int>> points;
        multiset<int> heights;
        for (auto &b: buildings) {
            points.emplace_back(b[0], -b[2]);
            points.emplace_back(b[1], b[2]);
        }
        sort(points.begin(), points.end());
        heights.insert(0);
        for (auto &p: points) {
            int x = p.first, h = abs(p.second);
            if (p.second < 0) {
                if (h > *heights.rbegin()) res.push_back({x, h});
                heights.insert(h);
            } else {
                heights.erase(heights.find(h));
                if (h > *heights.rbegin()) res.push_back({x, *heights.rbegin()});
            }
        }
        return res;
    }
};