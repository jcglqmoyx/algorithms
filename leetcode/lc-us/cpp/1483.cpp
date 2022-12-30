#include <bits/stdc++.h>

using namespace std;

class TreeAncestor {
    vector<vector<int>> f;
public:
    TreeAncestor(int n, vector<int> &parent) {
        int m = 0;
        for (int i = 1; i <= n; i <<= 1) m++;
        f.resize(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) f[i][0] = parent[i];
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (f[i][j - 1] != -1) {
                    f[i][j] = f[f[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        int mx = (int) log2(k);
        for (int i = 0; i <= mx && node != -1; i++) {
            if (k & (1 << i)) node = f[node][i];
        }
        return node;
    }
};