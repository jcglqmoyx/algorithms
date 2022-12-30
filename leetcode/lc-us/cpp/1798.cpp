#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMaximumConsecutive(vector<int> &coins) {
        sort(coins.begin(), coins.end());
        int sum = 0;
        for (int coin: coins) {
            if (coin > sum + 1) return sum + 1;
            sum += coin;
        }
        return sum + 1;
    }
};