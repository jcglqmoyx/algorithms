#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxXor(int n, vector<vector<int>> &edges, vector<int> &values) {
        v = move(values);
        s.resize(n);
        g.resize(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        trie = new Trie();
        dfs1(0, -1);
        dfs2(0, -1);
        return res;
    }

private:
    using LL = long long;
    vector<vector<int>> g;
    vector<int> v;
    vector<LL> s;
    LL res = 0;

    struct Trie {
        Trie *ne[2];

        Trie() : ne() {}

        void insert(LL x) {
            auto tr = this;
            for (int i = 46; i >= 0; i--) {
                int p = (int) (x >> i & 1);
                if (!tr->ne[p]) tr->ne[p] = new Trie();
                tr = tr->ne[p];
            }
        }

        LL query(LL x) {
            auto tr = this;
            LL ans = 0;
            for (int i = 46; i >= 0; i--) {
                if (!tr) break;
                int p = (int) (x >> i & 1);
                if (tr->ne[1 ^ p]) {
                    tr = tr->ne[p ^ 1], ans |= 1LL << i;
                } else {
                    tr = tr->ne[p];
                }
            }
            return ans;
        }
    };

    Trie *trie;

    LL dfs1(int u, int p) {
        LL sum = v[u];
        for (int x: g[u]) {
            if (x == p) continue;
            sum += dfs1(x, u);
        }
        s[u] = sum;
        return sum;
    }

    void dfs2(int u, int p) {
        res = max(res, trie->query(s[u]));
        for (int x: g[u]) {
            if (x == p) continue;
            dfs2(x, u);
        }
        trie->insert(s[u]);
    }
};