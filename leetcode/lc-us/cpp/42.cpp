#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int left_max = 0, right_max = 0, l = 0, r = (int) height.size() - 1, res = 0;
        while (l < r) {
            left_max = max(left_max, height[l]);
            right_max = max(right_max, height[r]);
            if (height[l] < height[r]) {
                res += left_max - height[l];
                l++;
            } else {
                res += right_max - height[r];
                r--;
            }
        }
        return res;
    }
};