#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> sandyLandManagement(int n) {
        vector<vector<int>> ans;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= i * 2 - 1; j += 4) {
                ans.push_back({i, j});
            }
        }
        ans.push_back({n, 1});
        if (n > 1) ans.push_back({n, n * 2 - 1});
        for (int i = 4; i < n * 2 - 1; i += 8) ans.push_back({n, i});
        for (int i = 7; i < n * 2 - 1; i += 8) ans.push_back({n, i});
        for (int i = 9; i < n * 2 - 1; i += 8) ans.push_back({n, i});
        return ans;
    }
};