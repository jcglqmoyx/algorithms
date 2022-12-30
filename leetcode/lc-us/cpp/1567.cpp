#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMaxLen(vector<int> &nums) {
        int f = 0, g = 0;
        int res = 0;
        for (int num: nums) {
            if (!num) {
                f = g = 0;
            } else if (num > 0) {
                f++;
                g = g ? g + 1 : 0;
            } else {
                int t = f;
                f = g ? g + 1 : 0;
                g = t + 1;
            }
            res = max(res, f);
        }
        return res;
    }
};