#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = (int) isConnected.size();
        f.resize(n);
        for (int i = 0; i < n; i++) f[i] = i;
        rank.resize(n, 1);
        count = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) connect(i, j);
            }
        }
        return count;
    }

private:
    vector<int> f, rank;
    int count;

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    void connect(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) return;
        if (rank[fx] > rank[fy]) swap(fx, fy);
        f[fx] = fy;
        rank[fy] += rank[fx];
        count--;
    }
};