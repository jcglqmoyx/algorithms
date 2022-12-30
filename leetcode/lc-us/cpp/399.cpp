#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        unordered_map<string, unordered_map<string, double>> paths;
        unordered_set<string> positions;
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            double dist = values[i];
            paths[a][b] = dist, paths[b][a] = 1 / dist;
            positions.insert(a), positions.insert(b);
        }
        for (auto &k: positions) {
            for (auto &i: positions) {
                for (auto &j: positions) {
                    if (paths[i][k] && paths[j][k]) {
                        paths[i][j] = paths[i][k] * paths[k][j];
                    }
                }
            }
        }
        vector<double> res;
        for (auto &q: queries) {
            string a = q[0], b = q[1];
            if (paths[a][b]) res.push_back(paths[a][b]);
            else res.push_back(-1);
        }
        return res;
    }
};
