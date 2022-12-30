#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges) {
        const int INF = 0x3f3f3f3f;
        vector<int> red(n, INF), blue(n, INF);
        path_red.resize(n), path_blue.resize(n);
        for (auto &e: red_edges) path_red[e[0]].push_back(e[1]);
        for (auto &e: blue_edges) path_blue[e[0]].push_back(e[1]);
        dist_red.resize(n, INF), dist_blue.resize(n, INF);
        dist_red[0] = 0, dist_blue[0] = 0;
        for (int ne: path_blue[0]) {
            if (ne != 0) {
                dfs(0, ne, true);
            }
        }
        for (int ne: path_red[0]) {
            if (ne != 0) {
                dfs(0, ne, false);
            }
        }
        vector<int> res(n);
        for (int i = 1; i < n; i++) {
            int mn = min(dist_red[i], dist_blue[i]);
            if (mn == INF) res[i] = -1;
            else res[i] = mn;
        }
        return res;
    }

private:
    vector<int> dist_red, dist_blue;
    vector<vector<int>> path_red, path_blue;

    void dfs(int last, int cur, bool flag) {
        if (flag) {
            dist_blue[cur] = dist_red[last] + 1;
            for (int ne: path_red[cur]) {
                if (dist_red[ne] > dist_blue[cur] + 1) dfs(cur, ne, false);
            }

        } else {
            dist_red[cur] = dist_blue[last] + 1;
            for (int ne: path_blue[cur]) {
                if (dist_blue[ne] > dist_red[cur] + 1) dfs(cur, ne, true);
            }
        }
    }
};