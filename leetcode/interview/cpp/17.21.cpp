#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int n = (int) height.size(), res = 0;
        int left_max = 0, right_max = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            if (height[l] <= height[r]) {
                left_max = max(left_max, height[l]);
                res += left_max - height[l];
                l++;
            } else {
                right_max = max(right_max, height[r]);
                res += right_max - height[r];
                r--;
            }
        }
        return res;
    }
};