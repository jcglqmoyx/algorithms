class Solution {
    static const int mod = 1e9 + 7;

    long long quick_power(long long a, long long b) {
        long long res = 0, temp = a;
        while (b) {
            if (b % 2) {
                res += temp;
            }
            b >>= 1;
            temp <<= 1;
            temp %= mod;
        }
        return res;
    }

    int C(int m, int n) {
        int k = 1;
        int ans = 1;
        while (k <= n) {
            ans = ((m - k + 1) * ans) / k;
            k++;
        }
        return ans;
    }

public:
    int keyboard(int k, int n) {
        long long dp[n + 1][27];
        for (int i = 0; i <= 26; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 26; j++) {
                dp[i][j] = 0;
                for (int t = 0; t <= i; t++) {
                    if (t > k) break;
                    if (t + (j - 1) * k < i) continue;
                    dp[i][j] += quick_power(C(i, t), dp[i - t][j - 1]);
                    dp[i][j] %= mod;
                }
            }
        }
        return (int) dp[n][26];
    }
};