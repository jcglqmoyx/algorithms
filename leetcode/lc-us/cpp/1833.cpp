#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int> &costs, int coins) {
        sort(costs.begin(), costs.end());
        int cnt = 0;
        for (int cost: costs) {
            if (coins >= cost) {
                cnt++;
                coins -= cost;
            } else {
                break;
            }
        }
        return cnt;
    }
};