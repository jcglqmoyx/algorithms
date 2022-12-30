#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int> &nums) {
        int ans = -1e6, diff = 1e6;
        for (int x: nums) {
            int d = abs(x);
            if (d < diff) {
                diff = d;
                ans = x;
            } else if (d == diff) {
                if (x > ans) {
                    ans = x;
                }
            }
        }
        return ans;
    }
};