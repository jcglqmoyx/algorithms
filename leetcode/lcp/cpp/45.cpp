#include <bits/stdc++.h>

using namespace std;

class Solution {
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
public:
    vector<vector<int>> bicycleYard(vector<int> &position, vector<vector<int>> &terrain, vector<vector<int>> &obstacle) {
        int n = (int) terrain.size(), m = (int) terrain[0].size();
        int x0 = position[0], y0 = position[1];
        vector<vector<int>> st(n, vector<int>(m, 0));
        st[x0][y0] = 1;
        vector<vector<unordered_set<int>>> map(n, vector<unordered_set<int>>(m, unordered_set<int>()));
        queue<vector<int>> q;
        q.push({x0, y0, terrain[x0][y0], 1});
        vector<vector<int>> res;
        while (!q.empty()) {
            for (int idx = (int) q.size(); idx; idx--) {
                auto t = q.front();
                q.pop();
                int x = t[0], y = t[1], h1 = t[2], speed = t[3];
                for (int i = 0; i < 4; i++) {
                    int a = x + dx[i], b = y + dy[i];
                    if (a < 0 || a == n || b < 0 || b == m) continue;
                    int s = speed + h1 - terrain[a][b] - obstacle[a][b];
                    if (s <= 0) continue;
                    if (s == 1 && !(a == x0 && b == y0)) res.push_back({a, b});
                    if (map[a][b].count(s)) continue;
                    map[a][b].insert(s);
                    q.push({a, b, terrain[a][b], s});
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};