#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>> &grid) {
        int n = (int) grid.size();
        unordered_map<string, int> S;
        for (int j = 0; j < n; j++) {
            string s;
            for (int i = 0; i < n; i++) {
                s += to_string(grid[i][j]) + ' ';
            }
            S[s]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            string s;
            for (int j = 0; j < n; j++) {
                s += to_string(grid[i][j]) + ' ';
            }
            res += S[s];
        }
        return res;
    }
};