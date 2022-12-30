#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries) {
        unordered_map<int, unordered_set<int>> row, col, dg, udg;
        vector<int> res;
        for (auto &l: lamps) {
            int x = l[0], y = l[1];
            row[x].insert(y);
            col[y].insert(x);
            dg[x + y].insert(x);
            udg[x - y].insert(x);
        }
        for (auto &r: queries) {
            int x = r[0], y = r[1];
            bool flag = false;
            if (!row[x].empty() || !col[y].empty() || !dg[x + y].empty() || !udg[x - y].empty()) flag = true;
            res.push_back(flag);
            for (int i = x - 1; i <= x + 1; i++) {
                for (int j = y - 1; j <= y + 1; j++) {
                    row[i].erase(j);
                    col[j].erase(i);
                    dg[i + j].erase(i);
                    udg[i - j].erase(i);
                }
            }
        }
        return res;
    }
};