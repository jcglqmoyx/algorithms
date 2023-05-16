#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int p[51];

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    int countCompleteComponents(int n, vector<vector<int>> &edges) {
        iota(p, p + n, 0);
        vector<unordered_set<int>> S(n);
        for (auto &e: edges) {
            p[find(e[0])] = p[find(e[1])];
            S[e[0]].insert(e[1]);
            S[e[1]].insert(e[0]);
        }
        bool st[51]{};
        int res = 0;
        for (int i = 0; i < n; i++) {
            int pi = find(i);
            if (st[pi]) continue;
            st[pi] = true;
            vector<int> v;
            for (int j = 0; j < n; j++) {
                if (find(j) == pi) v.push_back(j);
            }
            if (v.size() <= 2) res++;
            else {
                bool flag = true;
                for (int ii = 0; ii < v.size(); ii++) {
                    for (int jj = 0; jj < v.size(); jj++) {
                        if (ii != jj && !S[v[ii]].count(v[jj])) flag = false;
                    }
                }
                res += flag;
            }
        }
        return res;
    }
};