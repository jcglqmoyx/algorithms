#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = (int) prices.size();
        k = min(k, n / 2);
        vector<int> b(k + 1, -1e8), s(k + 1, -1e8);
        s[0] = 0;
        for (int x: prices) {
            for (int i = 1; i <= k; i++) {
                b[i] = max(b[i], s[i - 1] - x);
                s[i] = max(s[i], b[i] + x);
            }
        }
        return *max_element(s.begin(), s.end());
    }
};