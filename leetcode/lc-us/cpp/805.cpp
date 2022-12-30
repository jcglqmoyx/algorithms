#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int> &nums) {
        int n = (int) nums.size();
        if (n < 2) return false;
        double avg = (double) accumulate(nums.begin(), nums.end(), 0) / n;
        int m = n / 2;
        vector<vector<int>> map(m + 1, vector<int>());
        for (int i = 0; i < 1 << m; i++) {
            int cnt = 0, sum = 0;
            for (int j = 0; j < m; j++) {
                if (i >> j & 1) {
                    cnt++;
                    sum += nums[j];
                }
            }
            map[cnt].push_back(sum);
        }
        for (auto &v: map) sort(v.begin(), v.end());
        for (int i = 0; i < 1 << (n - m); i++) {
            int cnt = 0, sum = 0;
            for (int j = 0; j < n - m; j++) {
                if (i >> j & 1) {
                    cnt++;
                    sum += nums[m + j];
                }
            }
            for (int j = 0; j <= m; j++) {
                if (cnt + j == n || cnt + j == 0) continue;
                int l = 0, r = (int) map[j].size() - 1;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if ((double) (sum + map[j][mid]) / (cnt + j) < avg) l = mid + 1;
                    else r = mid;
                }
                if ((double) (sum + map[j][l]) / (cnt + j) == avg) return true;
            }
        }
        return false;
    }
};