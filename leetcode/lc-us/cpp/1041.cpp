#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
        int x = 0, y = 0, d = 0;
        for (char c: instructions) {
            if (c == 'G') x += dx[d], y += dy[d];
            else if (c == 'L') d = (d + 1) % 4;
            else d = (d + 3) % 4;
        }
        return x == 0 && y == 0 || d;
    }
};