#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = N << 1;

int h[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted) {
        memset(h, -1, sizeof h), idx = 0;
        memset(st, 0, sizeof st);
        unordered_set<int> S;
        for (int x: restricted) S.insert(x);
        for (auto edge: edges) {
            if (S.count(edge[0]) || S.count(edge[1])) continue;
            add(edge[0], edge[1]), add(edge[1], edge[0]);
        }
        queue<int> q;
        q.push(0);
        st[0] = true;
        int res = 1;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = h[x]; i != -1; i = ne[i]) {
                if (st[e[i]]) continue;
                st[e[i]] = true;
                q.push(e[i]);
                res++;
            }
        }
        return res;
    }
};