#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string evolutionaryRecord(vector<int> &parents) {
        int n = (int) parents.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            if (parents[i] != -1) {
                g[parents[i]].push_back(i);
            }
        }
        function<string(int)> dfs2 = [&](int u) -> string {
            vector<string> v(g[u].size());
            for (int i = 0; i < g[u].size(); i++) {
                v[i] = to_string(0) + dfs2(g[u][i]) + to_string(1);
            }
            sort(v.begin(), v.end());
            string res;
            for (string &s: v) res += s;
            return res;
        };
        string t = dfs2(0);
        while (!t.empty() && t.back() != '0') t.pop_back();
        return t;
    }
};