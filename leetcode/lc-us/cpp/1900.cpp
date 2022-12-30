#include <bits/stdc++.h>

using namespace std;

class Solution {
    static const int N = 30;
    int f[N][N][N], g[N][N][N];

    pair<int, int> dp(int n, int a, int b) {
        if (f[n][a][b]) return {f[n][a][b], g[n][a][b]};
        if (a + b == n + 1) return {1, 1};
        if (a + b > n + 1) {
            tie(f[n][a][b], g[n][a][b]) = dp(n, n + 1 - b, n + 1 - a);
            return {f[n][a][b], g[n][a][b]};
        }
        int half = (n + 1) / 2;
        int mn = 1e8, mx = -1e8;
        if (b <= half) {
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b - a; j++) {
                    auto[p, q] = dp(half, i + 1, i + j + 2);
                    mn = min(mn, p), mx = max(mx, q);
                }
            }
        } else {
            int b_prime = n + 1 - b;
            int mid = (n - 2 * b_prime + 1) / 2;
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b_prime - a; j++) {
                    auto[p, q] = dp(half, i + 1, i + j + mid + 2);
                    mn = min(mn, p), mx = max(mx, q);
                }
            }
        }
        return {mn + 1, mx + 1};
    }

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        if (firstPlayer > secondPlayer) swap(firstPlayer, secondPlayer);
        auto[mn, mx] = dp(n, firstPlayer, secondPlayer);
        return {mn, mx};
    }
};