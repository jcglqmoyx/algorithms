#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int racecar(int target) {
        struct State {
            int pos, step, direction;
        };
        int f[20010][15][2];
        memset(f, 0x3f, sizeof f);
        f[0][0][1] = 0;
        queue<State> q;
        q.push({0, 0, 1});
        while (!q.empty()) {
            State t = q.front();
            q.pop();
            int pos = t.pos, step = t.step, direction = t.direction;
            int val = f[pos][step][direction];
            if (pos == target) return val;
            int nx = pos + (1 << step) * (direction * 2 - 1);
            if (nx >= 0 && nx <= target * 2) {
                if (f[nx][step + 1][direction] > val + 1) {
                    f[nx][step + 1][direction] = val + 1;
                    q.push({nx, step + 1, direction});
                }
            }
            int reverse_direction = direction ^ 1;
            if (f[pos][0][reverse_direction] > val + 1) {
                f[pos][0][reverse_direction] = val + 1;
                q.push({pos, 0, reverse_direction});
            }
        }
        return -1;
    }
};