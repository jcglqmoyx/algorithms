#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>> &wall) {
        unordered_map<int, int> cnt;
        for (auto &line: wall) {
            int s = 0;
            for (int i = 0; i < line.size() - 1; i++) {
                s += line[i];
                cnt[s]++;
            }
        }
        int res = 0;
        for (auto[k, v]: cnt) {
            res = max(res, v);
        }
        return (int) wall.size() - res;
    }
};