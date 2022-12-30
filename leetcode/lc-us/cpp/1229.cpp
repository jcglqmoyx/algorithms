#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>> &s1, vector<vector<int>> &s2, int duration) {
        int n = (int) s1.size(), m = (int) s2.size();
        sort(s1.begin(), s1.end()), sort(s2.begin(), s2.end());
        for (int i = 0, j = 0; i < n && j < m;) {
            int x = max(s1[i][0], s2[j][0]), y = min(s1[i][1], s2[j][1]);
            if (y - x >= duration) return {x, x + duration};
            if (s1[i][1] > s2[j][1]) j++;
            else i++;
        }
        return {};
    }
};