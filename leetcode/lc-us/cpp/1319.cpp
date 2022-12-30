#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>> &connections) {
        if (connections.size() < n - 1) return -1;
        f.reserve(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) f[i] = i;
        for (const auto &connection: connections) connect(connection[0], connection[1]);
        int count = 0;
        for (int i = 0; i < n; i++) if (find(i) == i) count++;
        return count - 1;
    }

private:
    vector<int> f;
    vector<int> rank;

    void connect(int x, int y) {
        int fx = find(x), fy = find(y);
        if (x == y) return;
        if (rank[fx] > rank[fy]) swap(fx, fy);
        f[fx] = f[fy];
        rank[fy]++;
    }

    int find(int x) {
        if (f[x] == x) return x;
        else return f[x] = find(f[x]);
    }
};