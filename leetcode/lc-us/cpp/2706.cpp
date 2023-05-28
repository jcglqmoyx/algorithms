#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int buyChoco(vector<int> &prices, int money) {
        const int INF = 1e9;
        int a = INF, b = INF;
        for (int p: prices) {
            if (p < b) {
                if (p < a) b = a, a = p;
                else b = p;
            }
        }
        int s = a + b;
        if (s <= money) return money - s;
        return money;
    }
};