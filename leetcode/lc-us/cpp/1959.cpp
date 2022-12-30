#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSpaceWastedKResizing(vector<int> &nums, int k) {
        const int n = (int) nums.size(), INF = 1e9;
        k++;
        vector<vector<int>> f(n + 1, vector<int>(k + 1, INF));
        f[0][0] = 0;
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i && j <= k; j++) {
                for (int h = 0, u = i; u; u--) {
                    h = max(h, nums[u - 1]);
                    f[i][j] = min(f[i][j], f[u - 1][j - 1] + h * (i - u + 1) - (s[i] - s[u - 1]));
                }
            }
        }
        return f[n][k];
    }
};