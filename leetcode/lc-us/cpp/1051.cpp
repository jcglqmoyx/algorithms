#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int> &heights) {
        vector<int> cp(heights);
        sort(cp.begin(), cp.end());
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != cp[i]) {
                res++;
            }
        }
        return res;
    }
};