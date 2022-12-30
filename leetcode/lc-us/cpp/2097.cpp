#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs) {
        for (auto &p: pairs) {
            int x = p[0], y = p[1];
            in[y]++, out[x]++;
            paths[x].push_back(y);
        }
        for (auto &it: paths) {
            if (out[it.first] == in[it.first] + 1) {
                dfs(it.first);
                break;
            }
        }
        if (ans.empty()) dfs(paths.begin()->first);
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> paths;
    unordered_map<int, int> in, out;

    void dfs(int i) {
        if (paths[i].empty()) return;
        auto &ne = paths[i];
        while (!ne.empty()) {
            int j = ne.back();
            ne.pop_back();
            dfs(j);
            ans.push_back({i, j});
        }
    }
};