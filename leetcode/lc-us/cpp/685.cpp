#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n;
bool st1[N], st2[N];
int h[N], e[N], ne[N], idx;

bool st[N], in_stack[N], in_circle[N];
int stk[N], id;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u) {
    st[u] = true;
    stk[id++] = u;
    in_stack[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!st[j] && dfs(j)) return true;
        if (in_stack[j]) {
            while (stk[--id] != j) {
                in_circle[stk[id]] = true;
            }
            in_circle[j] = true;
            return true;
        }
    }
    in_stack[u] = false;
    id--;
    return false;
}

void work1(vector<vector<int>> &edges) {
    memset(h, -1, sizeof h), idx = 0;
    memset(st, false, sizeof st);
    memset(in_stack, false, sizeof in_stack);
    memset(in_circle, false, sizeof in_circle), id = 0;
    for (auto &edge: edges) add(edge[0], edge[1]);
    for (int i = 0; i < n; i++) {
        if (!st[i] && dfs(i)) {
            break;
        }
    }
    for (int i = n - 1; ~i; i--) {
        int x = edges[i][0], y = edges[i][1];
        if (in_circle[x] && in_circle[y]) {
            st1[i] = true;
        }
    }
}

void work2(vector<vector<int>> &edges) {
    memset(st, false, sizeof st);
    int p[N];
    memset(p, -1, sizeof p);
    for (int i = 0; i < n; i++) {
        int x = edges[i][1];
        if (p[x] != -1) {
            st2[i] = st2[p[x]] = true;
            break;
        } else {
            p[x] = i;
        }
    }
}

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        n = (int) edges.size();
        memset(st1, false, sizeof st1), memset(st2, false, sizeof st2);
        work1(edges);
        work2(edges);
        for (int i = n - 1; ~i; i--) {
            if (st1[i] && st2[i]) return edges[i];
        }
        for (int i = n - 1; ~i; i--) {
            if (st1[i] || st2[i]) return edges[i];
        }
        return {};
    }
};