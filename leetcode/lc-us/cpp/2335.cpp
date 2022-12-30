#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fillCups(vector<int> &amount) {
        sort(amount.begin(), amount.end());
        int a = amount[0], b = amount[1], c = amount[2];
        int res = c;
        if (c < a + b) {
            res += (a + b - c + 1) / 2;
        }
        return res;
    }
};