#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int low = 0, high = 999999;
        int ans;
        int n = (int) heights.size(), m = (int) heights[0].size();
        while (low <= high) {
            queue<pair<int, int>> q;
            q.push({0, 0});
            int mid = low + (high - low) / 2;
            vector<bool> seen(n * m);
            seen[0] = true;
            while (!q.empty()) {
                auto[x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int x_next = x + dx[i];
                    int y_next = y + dy[i];
                    if (x_next >= 0 && x_next < n && y_next >= 0 && y_next < m && !seen[x_next * m + y_next] &&
                        abs(heights[x][y] - heights[x_next][y_next]) <= mid) {
                        seen[x_next * m + y_next] = true;
                        q.push({x_next, y_next});
                    }
                }
            }
            if (seen[n * m - 1]) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
};