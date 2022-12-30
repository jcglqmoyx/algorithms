#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int regionsBySlashes(vector<string> &grid) {
        int n = (int) grid.size();
        f.resize(n * n * 4);
        for (int i = 0; i < f.size(); i++) f[i] = i;
        rank.resize(f.size(), 1);
        count = (int) f.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int index = 4 * (i * n + j);
                switch (grid[i][j]) {
                    case '/':
                        merge(index, index + 3);
                        merge(index + 1, index + 2);
                        break;
                    case '\\':
                        merge(index, index + 1);
                        merge(index + 2, index + 3);
                        break;
                    default:
                        merge(index, index + 1);
                        merge(index + 1, index + 2);
                        merge(index + 2, index + 3);
                        break;
                }
                if (i < n - 1) merge(index + 2, 4 * ((i + 1) * n + j));
                if (j < n - 1) merge(index + 1, index + 7);
            }
        }
        return count;
    }

private:
    vector<int> f;
    vector<int> rank;
    int count;

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) return;
        if (rank[fx] > rank[fy]) swap(fx, fy);
        f[fx] = fy;
        rank[fy] += rank[fx];
        count--;
    }
};