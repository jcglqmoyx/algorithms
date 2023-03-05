#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findValidSplit(vector<int> &nums) {
        int n = (int) nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int r[mx + 1];
        memset(r, -1, sizeof r);
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = 2; j * j <= x; j++) {
                if (x % j == 0) {
                    r[j] = i;
                    while (x % j == 0) x /= j;
                }
            }
            if (x > 1) r[x] = i;
        }
        int max_r = -1;
        for (int i = 0; i < n - 1; i++) {
            int x = nums[i];
            for (int j = 2; j * j <= x; j++) {
                if (x % j == 0) {
                    while (x % j == 0) x /= j;
                    max_r = max(max_r, r[j]);
                }
            }
            if (x > 1) max_r = max(max_r, r[x]);
            if (i >= max_r) return i;
        }
        return -1;
    }
};