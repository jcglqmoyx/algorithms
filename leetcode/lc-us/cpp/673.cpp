#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int n = (int) nums.size();
        int cnt = 0, max_len = 1;
        vector<int> f(n, 1), g(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (f[i] < f[j] + 1) {
                        f[i] = f[j] + 1;
                        g[i] = g[j];
                    } else if (f[i] == f[j] + 1) {
                        g[i] += g[j];
                    }
                }
            }
            if (f[i] > max_len) {
                max_len = f[i];
                cnt = g[i];
            } else if (f[i] == max_len) {
                cnt += g[i];
            }
        }
        return cnt;
    }
};