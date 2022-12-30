#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> res(length);
        for (int i = x1; i <= x2; i++) {
            res[(y * w + i) >> 5] |= 1 << (31 - i % 32);
        }
        return res;
    }
};