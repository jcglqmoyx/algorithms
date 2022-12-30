#include <bits/stdc++.h>

using namespace std;

const int K = 5;

class Solution {
public:
    int maxGroupNumber(vector<int> &tiles) {
        map<int, int> cnt;
        for (int tile: tiles) cnt[tile]++;
        vector<vector<int>> dp(K, vector<int>(K, -1));
        dp[0][0] = 0;
        int last = 0;
        for (auto[tile, freq]: cnt) {
            if (last != tile - 1) {
                int hi = dp[0][0];
                dp = vector<vector<int>>(K, vector<int>(K, -1));
                dp[0][0] = hi;
            }
            vector<vector<int>> ndp(K, vector<int>(K, -1));

            for (int i = 0; i < K; ++i)
                for (int j = 0; j < K; ++j) {
                    if (dp[i][j] < 0)
                        continue;

                    for (int k = 0; k <= min(i, min(j, freq)); ++k) {
                        int ni = j - k;

                        for (int nj = 0; nj <= min(K - 1, freq - k); ++nj) {
                            ndp[ni][nj] = max(ndp[ni][nj], dp[i][j] + k + (freq - k - nj) / 3);
                        }
                    }
                }

            dp = move(ndp);
            last = tile;
        }

        int ans = 0;
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < K; ++j) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};