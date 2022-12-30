#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n, m;

    vector<int> p, sz;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    int get(int r, int c) {
        return r * m + c;
    }

public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        n = (int) grid.size(), m = (int) grid[0].size();
        int root = n * m;
        for (int i = 0; i <= root; i++) {
            p.push_back(i);
            sz.push_back(1);
        }
        vector<bool> st;
        for (auto &hit: hits) {
            int r = hit[0], c = hit[1];
            if (grid[r][c]) st.push_back(true), grid[r][c] = 0;
            else st.push_back(false);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    if (!i) {
                        int p1 = find(get(i, j)), pr = find(root);
                        if (p1 != pr) {
                            p[p1] = pr;
                            sz[pr] += sz[p1];
                        }
                    }
                    for (int k = 0; k < 4; k++) {
                        int r = i + dx[k], c = j + dy[k];
                        if (r < 0 || r >= n || c < 0 || c >= m || !grid[r][c]) continue;
                        int p1 = find(get(i, j)), p2 = find(get(r, c));
                        if (p1 != p2) {
                            p[p1] = p2;
                            sz[p2] += sz[p1];
                        }
                    }
                }
            }
        }

        int last = sz[find(root)];
        vector<int> res(hits.size());
        for (int i = (int) hits.size() - 1; ~i; i--) {
            int r = hits[i][0], c = hits[i][1];
            if (st[i]) {
                grid[r][c] = 1;
                int x = get(r, c);
                if (!r) {
                    int p1 = find(x), p2 = find(root);
                    if (p1 != p2) {
                        p[p1] = p2;
                        sz[p2] += sz[p1];
                    }
                }
                for (int k = 0; k < 4; k++) {
                    int nr = r + dx[k], nc = c + dy[k];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m || !grid[nr][nc]) continue;
                    int p1 = find(x), p2 = find(get(nr, nc));
                    if (p1 != p2) {
                        p[p1] = p2;
                        sz[p2] += sz[p1];
                    }
                }
                res[i] = max(0, sz[find(root)] - last - 1);
                last = sz[find(root)];
            }
        }

        return res;
    }
};