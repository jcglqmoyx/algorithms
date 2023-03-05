#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = N << 1;

int h[N], e[M], ne[M], idx;
int yes[N], no[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
public:
    int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guesses, int k) {
        int n = (int) edges.size() + 1;
        if (!k) return n;
        memset(h, -1, sizeof(int) * n), idx = 0;
        memset(yes, 0, sizeof(int) * n);
        memset(no, 0, sizeof(int) * n);
        for (auto &edge: edges) {
            int x = edge[0], y = edge[1];
            add(x, y), add(y, x);
        }

        unordered_map<int, unordered_set<int>> S;
        for (auto &guess: guesses) {
            int p = guess[0], c = guess[1];
            S[p].insert(c);
        }

        int cnt_right = 0;

        function<void(int, int)> dfs1 = [&](int u, int p) {
            for (int i = h[u]; ~i; i = ne[i]) {
                int j = e[i];
                if (j == p) continue;
                if (S[u].count(j)) {
                    cnt_right++;
                }
                dfs1(j, u);
            }
        };

        dfs1(0, -1);

        int res = cnt_right >= k ? 1 : 0;

        function<void(int, int)> dfs2 = [&](int u, int p) {
            if (p != -1) {
                yes[u] = yes[p], no[u] = no[p];
                if (S[p].count(u)) yes[u]++;
                if (S[u].count(p)) no[u]++;
                if (cnt_right - yes[u] + no[u] >= k) res++;
            }

            for (int i = h[u]; ~i; i = ne[i]) {
                int j = e[i];
                if (j == p) continue;
                dfs2(j, u);
            }
        };

        dfs2(0, -1);
        return res;
    }
};