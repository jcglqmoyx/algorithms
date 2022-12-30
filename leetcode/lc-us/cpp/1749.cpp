#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int> &nums) {
        int mx = -2e9, mn = 2e9;
        int s1 = 0, s2 = 0;
        for (int x: nums) {
            s1 += x;
            s2 += x;
            if (s1 <= 0) {
                s1 = 0;
            }
            if (s2 >= 0) {
                s2 = 0;
            }
            mx = max(mx, s1);
            mn = min(mn, s2);
        }
        return max(mx, abs(mn));
    }
};