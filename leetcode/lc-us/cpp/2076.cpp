#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> p;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

public:
    vector<bool> friendRequests(int n, vector<vector<int>> &restrictions, vector<vector<int>> &requests) {
        p.resize(n);
        for (int i = 0; i < n; i++) p[i] = i;
        vector<bool> res;
        for (auto &request: requests) {
            bool flag = true;
            int x = request[0], y = request[1];
            int px = find(x), py = find(y);
            for (auto &restriction: restrictions) {
                int u = find(restriction[0]), v = find(restriction[1]);
                if (px == u && py == v || px == v && py == u) {
                    flag = false;
                    break;
                }
            }
            res.push_back(flag);
            if (flag) p[px] = py;
        }
        return res;
    }
};