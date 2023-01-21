#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSideJumps(vector<int> &obstacles) {
        const int INF = 1e9;
        int a = 1, b = 0, c = 1;
        for (int i = 1; i < obstacles.size(); i++) {
            int x = INF, y = INF, z = INF;
            switch (obstacles[i]) {
                case 1:
                    y = min(b, c + 1);
                    z = min(c, b + 1);
                    break;
                case 2:
                    x = min(a, c + 1);
                    z = min(c, a + 1);
                    break;
                case 3:
                    x = min(a, b + 1);
                    y = min(b, a + 1);
                    break;
                default:
                    x = min(a, min(b, c) + 1);
                    y = min(b, min(a, c) + 1);
                    z = min(c, min(a, b) + 1);
                    break;
            }
            a = x, b = y, c = z;
        }
        return min(a, min(b, c));
    }
};