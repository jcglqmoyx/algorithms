#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int n = (int) factory.size(), m = (int) robot.size();
        long long f[m + 1];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = m; j >= 1; j--) {
                long long cost = 0;
                for (int k = 1; k <= min(factory[i][1], j); k++) {
                    cost += abs(factory[i][0] - robot[j - k]);
                    f[j] = min(f[j], f[j - k] + cost);
                }
            }
        }
        return f[m];
    }
};