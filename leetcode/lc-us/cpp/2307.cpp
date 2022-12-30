#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<string, string> p;
    unordered_map<string, double> factor;

    string find(string x) {
        if (p[x] == x) return x;
        string tmp = p[x];
        p[x] = find(p[x]);
        factor[x] *= factor[tmp];
        return p[x];
    }

    void add(const string &x, const string &y, double value) {
        string px = find(x), py = find(y);
        if (px != py) {
            p[px] = py;
            factor[px] = factor[y] * value / factor[x];
        }
    }

public:
    bool checkContradictions(vector<vector<string>> &equations, vector<double> &values) {
        for (int i = 0; i < equations.size(); i++) {
            auto &x = equations[i][0], &y = equations[i][1];
            if (!p.count(x)) {
                p[x] = x;
                factor[x] = 1;
            }
            if (!p.count(y)) {
                p[y] = y;
                factor[y] = 1;
            }
            if (find(x) == find(y)) {
                if (fabs(factor[x] / factor[y] - values[i]) > 1e-5) return true;
            }
            add(x, y, values[i]);
        }
        return false;
    }
};