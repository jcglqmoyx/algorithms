#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = N << 1;

bool st[N];
int h[N], e[M], ne[M], idx = 0;

class Solution {
    int hash[N][26];

    vector<int> dfs(string &s, int u) {
        vector<int> cnt(26);
        cnt[s[u] - 'a']++;
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (!st[j]) {
                st[j] = true;
                auto t = dfs(s, j);
                for (int k = 0; k < 26; k++) {
                    cnt[k] += t[k];
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            hash[u][i] = cnt[i];
        }
        return cnt;
    };
public:
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
        idx = 0;
        memset(h, -1, sizeof h);
        memset(st, false, sizeof st);
        memset(hash, 0, sizeof hash);

        for (auto &edge: edges) {
            e[idx] = edge[1], ne[idx] = h[edge[0]], h[edge[0]] = idx++;
            e[idx] = edge[0], ne[idx] = h[edge[1]], h[edge[1]] = idx++;
        }
        vector<int> res(n);
        st[0] = true;
        dfs(labels, 0);
        for (int i = 0; i < n; i++) {
            res[i] = hash[i][labels[i] - 'a'];
        }
        return res;
    }
};