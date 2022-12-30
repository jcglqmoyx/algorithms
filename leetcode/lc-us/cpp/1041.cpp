#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int d = 0;
        int x = 0, y = 0;
        for (int i = 0; i < 4; i++) {
            for (char c: instructions) {
                if (c == 'G') {
                    x += dx[d], y += dy[d];
                } else if (c == 'L') {
                    d = (d + 3) % 4;
                } else if (c == 'R') {
                    d = (d + 1) % 4;
                }
            }
        }
        return x == 0 && y == 0 || d;
    }
};