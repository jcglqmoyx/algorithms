#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countLatticePoints(vector<vector<int>> &circles) {
        int cnt = 0;
        for (int x = 0; x <= 200; x++) {
            for (int y = 0; y <= 200; y++) {
                bool ok = false;
                for (auto &c: circles) {
                    int a = c[0], b = c[1], r = c[2];
                    int dx = a - x, dy = b - y;
                    if (dx * dx + dy * dy <= r * r) {
                        ok = true;
                        break;
                    }
                }
                if (ok) cnt++;
            }
        }
        return cnt;
    }
};