#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int> &nums) {
        const int N = 1005;
        int f[N][N];
        memset(f, 0, sizeof f);
        for (size_t i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j] + 500;
                f[i][diff] = max(f[i][diff], f[j][diff] + 1);
                f[i][diff] = max(f[i][diff], 2);
            }
        }
        int res = 0;
        for (auto &i: f) {
            for (int &j: i) {
                res = max(res, j);
            }
        }
        return res;
    }
};