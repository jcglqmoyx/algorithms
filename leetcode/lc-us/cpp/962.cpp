#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> p(n);
        for (int i = 0; i < n; i++) p[i] = i;
        sort(p.begin(), p.end(), [&](int a, int b) {
            if (nums[a] != nums[b]) return nums[a] < nums[b];
            return a < b;
        });
        int res = 0;
        for (int leftmost = p[0], j = 1; j < n; j++) {
            res = max(res, p[j] - leftmost);
            leftmost = min(leftmost, p[j]);
        }
        return res;
    }
};