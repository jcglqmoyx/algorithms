#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int l = 0, r = 0;
        for (auto &row: mat) {
            l += row.front();
            r += row.back();
        }
        function<void(int, int, int, int &)> dfs = [&](int row, int sum, int x, int &cnt) {
            if (row == mat.size() || sum > x || cnt > k) return;
            for (int i = 0; i < mat[row].size(); i++) {
                int t = sum + mat[row][i] - mat[row][0];
                if (t > x) break;
                if (i) cnt++;
                dfs(row + 1, t, x, cnt);
            }
        };
        int base = l;
        while (l < r) {
            int m = (l + r) >> 1;
            int cnt = 1;
            dfs(0, base, m, cnt);
            if (cnt < k) l = m + 1;
            else r = m;
        }
        return l;
    }
};