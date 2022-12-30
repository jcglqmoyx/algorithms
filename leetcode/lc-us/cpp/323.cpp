#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>> &edges) {
        f.reserve(n);
        rank.resize(n, 1);
        count = n;
        for (int i = 0; i < n; i++) f.push_back(i);
        for (const vector<int> &edge: edges) {
            connect(edge[0], edge[1]);
        }
        return count;
    }

private:
    vector<int> f;
    int count;
    vector<int> rank;

    int find(int x) {
        return x == f[x] ? x : find(f[x]);
    }

    void connect(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) return;
        if (rank[fx] < rank[fy]) swap(fx, fy);
        f[fy] = fx;
        rank[fx]++;
        count--;
    }
};