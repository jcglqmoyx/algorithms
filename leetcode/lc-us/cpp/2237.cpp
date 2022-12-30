#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int meetRequirement(int n, vector<vector<int>> &lights, vector<int> &requirement) {
        vector<int> b(n + 1);
        for (auto &light: lights) {
            int x = max(0, light[0] - light[1]), y = min(n - 1, light[0] + light[1]);
            b[x]++;
            if (y + 1 < n) b[y + 1]--;
        }
        for (int i = 1; i < n; i++) {
            b[i] += b[i - 1];
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] >= requirement[i]) cnt++;
        }
        return cnt;
    }
};