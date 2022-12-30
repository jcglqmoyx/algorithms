#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int> &piles) {
        int coins = 0;
        sort(piles.begin(), piles.end());
        for (int i = (int) piles.size() - 2; i >= (int) piles.size() / 3; i -= 2) {
            coins += piles[i];
        }
        return coins;
    }
};