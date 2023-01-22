#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<int> &nums, int k) {
        int n = (int) nums.size();
        int f[n + 1];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            int map[n];
            memset(map, 0, sizeof map);
            int cnt = 0;
            for (int j = i; j >= 1; j--) {
                map[nums[j - 1]]++;

                if (map[nums[j - 1]] == 2) {
                    cnt += 2;
                } else if (map[nums[j - 1]] > 2) {
                    cnt++;
                }

                f[i] = min(f[i], f[j - 1] + cnt + k);
            }
        }
        return f[n];
    }
};