#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = (int) edges.size();
        f.reserve(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i < n + 1; i++) f[i] = i;
        for (auto &edge: edges) if (!connect(edge[0], edge[1])) return edge;
        return {};
    }

private:
    vector<int> f, rank;

    bool connect(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return false;
        if (rank[fx] > rank[fy]) swap(fx, fy);
        f[fx] = fy;
        rank[fy] += rank[fx];
        return true;
    }

    int find(int x) {
        if (f[x] == x) return x;
        else return f[x] = find(f[x]);
    }
};