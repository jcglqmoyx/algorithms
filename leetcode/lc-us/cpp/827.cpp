#include <bits/stdc++.h>

using namespace std;

class Solution {
    int max_size;
    vector<int> p, rk;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void connect(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rk[px] > rk[py]) swap(px, py);
        p[px] = py;
        rk[py] += rk[px];
        max_size = max(max_size, rk[py]);
    }

public:
    int largestIsland(vector<vector<int>> &grid) {
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        int n = (int) grid.size(), m = n * n;
        max_size = 1;
        p.resize(m), rk.resize(m);
        for (int i = 0; i < m; i++) p[i] = i, rk[i] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    for (int idx = 0; idx < 4; idx++) {
                        int a = i + dx[idx], b = j + dy[idx];
                        if (a < 0 || a == n || b < 0 || b == n) continue;
                        if (grid[a][b]) {
                            connect(i * n + j, a * n + b);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) {
                    int sum = 1;
                    unordered_set<int> hash;
                    for (int it = 0; it < 4; it++) {
                        int a = i + dx[it], b = j + dy[it];
                        if (a < 0 || a == n || b < 0 || b == n || !grid[a][b]) continue;
                        int root = find(a * n + b);
                        if (!hash.count(root)) sum += rk[root];
                        hash.insert(root);
                    }
                    max_size = max(max_size, sum);
                }
            }
        }
        return max_size;
    }
};