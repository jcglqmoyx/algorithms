#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxStudents(vector<vector<char>> &seats) {
        int n = (int) seats.size(), m = (int) seats[0].size();
        vector<int> g(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (seats[i][j] == '.') {
                    g[i] |= 1 << j;
                }
            }
        }
        int f[n][1 << m];
        memset(f, -1, sizeof f);
        function<int(int, int)> dp = [&](int row, int st) -> int {
            if (f[row][st] != -1) return f[row][st];
            if (!st) return row < n - 1 ? dp(row + 1, g[row + 1]) : 0;
            f[row][st] = 0;
            for (int choice = st; choice; choice = (choice - 1) & st) {
                if (choice & (choice << 1)) continue;
                int cnt = __builtin_popcount(choice);
                int next = 0;
                if (row + 1 < n) {
                    int st_next = g[row + 1];
                    for (int next_choice = st_next; next_choice; next_choice = (next_choice - 1) & st_next) {
                        if (next_choice & (next_choice << 1)) continue;
                        if ((next_choice << 1) & choice || (next_choice >> 1) & choice) continue;
                        next = max(next, dp(row + 1, next_choice));
                    }
                    next = max(next, dp(row + 1, 0));
                }
                f[row][st] = max(f[row][st], cnt + next);
            }
            f[row][st] = max(f[row][st], dp(row, 0));
            return f[row][st];
        };
        return dp(0, g[0]);
    }
};