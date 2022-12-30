#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>> &edges) {
        if (n != edges.size() + 1) return false;
        f.reserve(n);
        for (int i = 0; i < n; i++) {
            f.push_back(i);
        }
        return all_of(edges.begin(), edges.end(), [&](vector<int> &edge) {
            return !connect(edge[0], edge[1]);
        });
    }

private:
    vector<int> f;

    int find(int x) {
        return f[x] == x ? x : find(f[x]);
    }

    bool connect(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) return true;
        f[fx] = fy;
        return false;
    }
};