#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>> &increase, vector<vector<int>> &requirements) {
        int n = (int) increase.size();
        vector<vector<int>> s(n + 1, vector<int>(3));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                s[i][j] = s[i - 1][j] + increase[i - 1][j];
            }
        }
        vector<int> res;
        for (auto &requirement: requirements) {
            int l = 0, r = n + 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (s[mid][0] >= requirement[0] && s[mid][1] >= requirement[1] && s[mid][2] >= requirement[2]) r = mid;
                else l = mid + 1;
            }
            if (l == n + 1) res.push_back(-1);
            else res.push_back(l);
        }
        return res;
    }
};