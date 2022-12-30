#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix) {
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        const int OFFSET = m + 1;
        int max_r[n], max_c[m];
        memset(max_r, 0, sizeof max_r);
        memset(max_c, 0, sizeof max_c);
        int p[n + m];
        for (int i = 0; i < n + m; i++) p[i] = i;
        function<int(int)> find = [&](int x) {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        };

        map<int, vector<int>> M;

        unordered_map<int, vector<int>> pool;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                M[matrix[i][j]].push_back(i * OFFSET + j);
            }
        }
        vector<vector<int>> res(n, vector<int>(m));
        for (auto &[val, points]: M) {
            for (int point: points) {
                int r = point / OFFSET, c = point % OFFSET;
                p[find(r)] = find(c + n);
            }
            pool.clear();
            for (int point: points) {
                pool[find(point / OFFSET)].push_back(point);
            }
            for (auto &[root, pos]: pool) {
                int rank = 0;
                for (int point: pos) {
                    int r = point / OFFSET, c = point % OFFSET;
                    rank = max(rank, max(max_r[r], max_c[c]));
                }
                rank++;
                for (int point: pos) {
                    int r = point / OFFSET, c = point % OFFSET;
                    res[r][c] = rank;
                    max_r[r] = max_c[c] = rank;
                    p[r] = r, p[c + n] = c + n;
                }
            }
        }
        return res;
    }
};