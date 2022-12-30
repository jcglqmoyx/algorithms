#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>> &grid) {
        int n = (int) grid.size(), ans = 0;
        int low = 0, high = n * n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            vector<bool> seen(n * n);
            queue<pair<int, int>> q;
            q.push({0, 0});
            while (!q.empty()) {
                auto[x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int mx = x + dx[i];
                    int my = y + dy[i];
                    if (mx >= 0 && mx < n && my >= 0 && my < n && !seen[mx * n + my] && grid[mx][my] <= mid) {
                        q.push({mx, my});
                        seen[mx * n + my] = true;
                    }
                }
            }
            if (seen[n * n - 1]) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return max(ans, grid[0][0]);
    }

private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
};