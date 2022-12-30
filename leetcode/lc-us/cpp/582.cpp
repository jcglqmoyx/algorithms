#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        for (int i = 0; i < pid.size(); i++) {
            children[ppid[i]].push_back(pid[i]);
        }
        res.push_back(kill);
        dfs(kill);
        return res;
    }

private:
    vector<int> res;
    unordered_map<int, vector<int>> children;

    void dfs(int u) {
        if (children[u].empty()) return;
        for (int child: children[u]) {
            res.push_back(child);
            dfs(child);
        }
    }
};