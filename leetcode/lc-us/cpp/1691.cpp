#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxHeight(vector<vector<int>> &cuboids) {
        int n = (int) cuboids.size();
        for (auto &cuboid: cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());
        vector<int> f(n);
        int res = 0;
        for (int j = 0; j < n; j++) {
            f[j] = cuboids[j][2];
            for (int i = 0; i < j; i++) {
                if (cuboids[j][0] >= cuboids[i][0] && cuboids[j][1] >= cuboids[i][1] &&
                    cuboids[j][2] >= cuboids[i][2]) {
                    f[j] = max(f[j], f[i] + cuboids[j][2]);
                }
            }
            res = max(res, f[j]);
        }
        return res;
    }
};