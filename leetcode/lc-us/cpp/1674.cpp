#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(vector<int> &nums, int limit) {
        vector<int> d((limit << 1) + 2);
        int n = (int) nums.size();
        for (int i = 0; i < n >> 1; i++) {
            int x = nums[i], y = nums[n - 1 - i];
            d[2] += 2, d[limit << 1 | 1] -= 2;
            d[1 + min(x, y)]--, d[limit + max(x, y) + 1]++;
            d[x + y]--, d[x + y + 1]++;
        }
        int res = n;
        for (int i = 2; i <= limit * 2; i++) {
            d[i] += d[i - 1];
            res = min(res, d[i]);
        }
        return res;
    }
};