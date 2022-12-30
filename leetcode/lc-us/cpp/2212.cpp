#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> a;
    int max_points = 0;
    vector<int> ans;

    void dfs(int numArrows, int u, vector<int> b) {
        if (numArrows == 0 || u == 12) {
            int p = 0;
            for (int i = 0; i < 12; i++) {
                if (a[i] < b[i]) p += i;
            }
            if (p > max_points) {
                if (numArrows) {
                    b[11] += numArrows;
                }
                ans = b, max_points = p;
            }
            return;
        }
        dfs(numArrows, u + 1, b);
        if (numArrows > a[u]) {
            b[u] = a[u] + 1;
            dfs(numArrows - a[u] - 1, u + 1, b);
        }
    }

public:
    vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows) {
        a = aliceArrows;
        vector<int> b(12);
        dfs(numArrows, 0, b);
        return ans;
    }
};