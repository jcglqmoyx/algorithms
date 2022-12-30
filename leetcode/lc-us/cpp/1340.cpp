#include <bits/stdc++.h>

using namespace std;

class Solution {
    static constexpr int N = 1010;
    int n;
    int f[N];

    void dfs(vector<int> &arr, int d, int u) {
        if (f[u] != -1) return;
        f[u] = 1;
        for (int i = u - 1; u - i <= d && i >= 0 && arr[u] > arr[i]; i--) {
            dfs(arr, d, i);
            f[u] = max(f[u], f[i] + 1);
        }
        for (int i = u + 1; i - u <= d && i < n && arr[u] > arr[i]; i++) {
            dfs(arr, d, i);
            f[u] = max(f[u], f[i] + 1);
        }
    }

public:
    int maxJumps(vector<int> &arr, int d) {
        n = (int) arr.size();
        memset(f, -1, sizeof f);
        int res = 0;
        for (int i = 0; i < n; i++) dfs(arr, d, i);
        for (int i = 0; i < n; i++) res = max(res, f[i]);
        return res;
    }
};