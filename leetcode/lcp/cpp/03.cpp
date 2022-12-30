#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool robot(string command, vector<vector<int>> &obstacles, int x, int y) {
        if (!x && !y) return true;
        int dx = 0, dy = 0;
        for (char c: command) {
            if (c == 'U') dy++;
            else if (c == 'R') dx++;
        }
        if (dx == 0 && dy == 0) return false;
        if (dx == 0 && y % dy) return false;
        if (dy == 0 && x % dx) return false;
        while (!obstacles.empty() && (obstacles.back()[0] > x || obstacles.back()[1] > y)) obstacles.pop_back();
        int a = 0, b = 0;
        for (char c: command) {
            if (c == 'U') b++;
            else if (c == 'R') a++;
            for (auto &o: obstacles) {
                int p = o[0], q = o[1];
                if ((p - a) % dx == 0) {
                    if ((q - b) % dy == 0 && (p - a) / dx == (q - b) / dy) {
                        return false;
                    }
                }
            }
            if ((x - a) % dx == 0 && (y - b) % dy == 0) {
                if ((x - a) / dx == (y - b) / dy) return true;
            }
        }
        return false;
    }
};