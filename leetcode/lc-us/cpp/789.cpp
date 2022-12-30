#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
        int distance = abs(target[0]) + abs(target[1]);
        for (auto &ghost: ghosts) {
            int dis = abs(target[0] - ghost[0]) + abs(target[1] - ghost[1]);
            if (dis <= distance) return false;
        }
        return true;
    }
};