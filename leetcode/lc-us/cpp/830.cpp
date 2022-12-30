#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = (int) s.size();
        vector<vector<int>> large_group_positions;
        for (int i = 0; i < n - 2; i++) {
            if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
                int j = i + 2;
                while (j < n && s[j] == s[j + 1]) {
                    j++;
                }
                large_group_positions.push_back({i, j});
                i = j;
            }
        }
        return large_group_positions;
    }
};