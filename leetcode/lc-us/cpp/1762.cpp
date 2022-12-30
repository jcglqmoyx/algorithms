#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findBuildings(vector<int> &heights) {
        vector<int> res;
        int mx = 0;
        for (int i = (int) heights.size() - 1; i >= 0; i--) {
            if (heights[i] > mx) {
                res.push_back(i);
            }
            mx = max(mx, heights[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};