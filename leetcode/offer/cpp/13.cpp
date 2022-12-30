#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        int count = 0;
        queue<pair<int, int>> positions;
        positions.push({0, 0});
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[0][0] = 1;
        while (!positions.empty()) {
            count++;
            auto[x, y] = positions.front();
            positions.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && get_digit(nx) + get_digit(ny) <= k) {
                    positions.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
        }
        return count;
    }

private:
    static int get_digit(int n) {
        int digits = 0;
        while (n) {
            digits += n % 10;
            n /= 10;
        }
        return digits;
    }
};