#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCount(vector<int> &coins) {
        int count = 0;
        for (int coin: coins) {
            count += (coin + 1) / 2;
        }
        return count;
    }
};