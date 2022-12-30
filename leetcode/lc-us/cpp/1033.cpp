#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x = min(min(a, b), c);
        int z = max(max(a, b), c);
        int y = a + b + c - x - z;
        if (y - x == 1 && z - y == 1) {
            return {0, 0};
        }
        if (y - x <= 2 || z - y <= 2) {
            return {1, z - y + y - x - 2};
        } else return {2, z - y + y - x - 2};
    }
};