#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxGeneticDifference(vector<int> &parents, vector<vector<int>> &queries) {
        using PII = pair<int, int>;

        int n = (int) parents.size();
        int h[n], e[n], ne[n], idx = 0;
        memset(h, -1, sizeof h);

        function<void(int, int)> add = [&](int a, int b) {
            e[idx] = b, ne[idx] = h[a], h[a] = idx++;
        };

        int root;
        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) root = i;
            else add(parents[i], i);
        }

        int m = (int) queries.size();
        vector<int> res(m);

        vector<vector<PII>> v(n);
        for (int i = 0; i < m; i++) {
            int node = queries[i][0], val = queries[i][1];
            v[node].push_back({i, val});
        }

        auto trie = new Trie();

        function<void(int)> dfs = [&](int u) {
            trie->update(u, 1);
            if (!v[u].empty()) {
                for (auto &t: v[u]) {
                    int idx = t.first, val = t.second;
                    res[idx] = trie->query(val);
                }
            }
            for (int i = h[u]; ~i; i = ne[i]) dfs(e[i]);
            trie->update(u, -1);
        };

        dfs(root);

        return res;
    }

private:
    struct Trie {
        int cnt;
        Trie *ne[2];

        Trie() : cnt(0), ne() {}

        void update(int x, int dt) {
            auto trie = this;
            for (int i = 17; i >= 0; i--) {
                int j = x >> i & 1;
                if (!trie->ne[j]) trie->ne[j] = new Trie();
                trie = trie->ne[j];
                trie->cnt += dt;
            }
        }

        int query(int x) {
            int res = 0;
            auto trie = this;
            for (int i = 17; i >= 0; i--) {
                int j = x >> i & 1;
                int k = j ^ 1;
                if (trie->ne[k] && trie->ne[k]->cnt) {
                    res = res * 2 + 1;
                    trie = trie->ne[k];
                } else if (trie->ne[j] && trie->ne[j]->cnt) {
                    res = res * 2;
                    trie = trie->ne[j];
                } else break;
            }
            return res;
        }
    };
};