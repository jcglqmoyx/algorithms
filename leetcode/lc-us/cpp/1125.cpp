#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people) {
        int n = (int) req_skills.size(), m = (int) people.size();
        unordered_map<string, int> skill_map;
        vector<int> p(m);
        for (int i = 0; i < n; i++) {
            skill_map[req_skills[i]] = i;
        }
        for (int i = 0; i < m; i++) {
            for (auto &skill: people[i]) {
                p[i] |= 1 << skill_map[skill];
            }
        }
        vector<pair<int, int>> path(1 << n);
        vector<int> f(1 << n, n + 1);
        f[0] = 0;
        for (int i = 0; i < 1 << n; i++) {
            for (int j = 0; j < m; j++) {
                int v = i | p[j];
                if (f[v] > f[i] + 1) {
                    f[v] = f[i] + 1;
                    path[v] = {i, j};
                }
            }
        }
        vector<int> res;
        for (int state = (1 << n) - 1; state;) {
            res.push_back(path[state].second);
            state = path[state].first;
        }
        return res;
    }
};