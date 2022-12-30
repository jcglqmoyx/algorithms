#include <bits/stdc++.h>

using namespace std;

const int N = 1005, M = N << 1;

int h[N], e[M], ne[M], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
    int n, res;
    vector<int> w;

    int dfs(int u, int p, int sum1, int sum2) {
        int sum = w[u];
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == p) continue;
            int t = dfs(j, u, sum1, sum2);
            sum ^= t;
            if (sum1 != -1) {
                int a[3] = {sum2, t, sum1 ^ t};
                sort(a, a + 3);
                res = min(res, a[2] - a[0]);
            }
        }
        return sum;
    }

public:
    int minimumScore(vector<int> &nums, vector<vector<int>> &edges) {
        n = (int) nums.size(), res = 1e8, w = nums;
        for (int i = 0; i < n - 1; i++) {
            memset(h, -1, sizeof h), idx = 0;
            for (int j = 0; j < n - 1; j++) {
                if (i != j) {
                    int x = edges[j][0], y = edges[j][1];
                    add(x, y), add(y, x);
                }
            }
            int sum1 = dfs(edges[i][0], -1, -1, -1), sum2 = dfs(edges[i][1], -1, -1, -1);
            dfs(edges[i][0], -1, sum1, sum2), dfs(edges[i][1], -1, sum2, sum1);
        }
        return res;
    }
};