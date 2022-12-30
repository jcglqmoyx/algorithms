#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int> &time) {
        using LL = long long;
        int count[60] = {};
        for (int i: time) {
            count[i % 60]++;
        }
        int res = (LL) count[0] * (count[0] - 1) / 2 + (LL) count[30] * (count[30] - 1) / 2;
        for (int i = 1; i < 30; i++) {
            res += count[i] * count[60 - i];
        }
        return res;
    }
};