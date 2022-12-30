#include <bits/stdc++.h>

#define V vector

using namespace std;

class Solution {
public:
    V<double> calcEquation(V<V<string>> &equations, V<double> &values, V<V<string>> &queries) {
        unordered_map<string, vector<pair<string, double>>> path;
        for (int i = 0; i < equations.size(); i++) {
            string x = equations[i][0], y = equations[i][1];
            double z = values[i];
            path[x].push_back({y, z}), path[y].push_back({x, 1.0 / z});
        }
        int n = (int) queries.size();
        V<double> res(n);
        for (int i = 0; i < n; i++) {
            string x = queries[i][0], y = queries[i][1];
            if (!path.count(x) || !path.count(y)) res[i] = -1.0;
            else d = 1, 0, r = -1.0, st.clear(), dfs(path, x, y), res[i] = r;
        }
        return res;
    }

private:
    double d, r;
    unordered_set<string> st;

    void dfs(unordered_map<string, vector<pair<string, double>>> path, string &x, string &y) {
        if (x == y) {
            r = d;
            return;
        }
        if (st.count(x)) return;
        for (auto &ne: path[x]) {
            double tmp = d;
            d *= ne.second;
            st.insert(x);
            dfs(path, ne.first, y);
            d = tmp;
        }
    }
};