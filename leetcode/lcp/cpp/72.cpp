#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> supplyWagon(vector<int> &supplies) {
        auto n = supplies.size(), m = (n + 1) / 2;
        for (int it = 0; it < m; it++) {
            int mn = 1e9, idx;
            for (int i = 0; i < n - it - 1; i++) {
                int s = supplies[i] + supplies[i + 1];
                if (s < mn) mn = s, idx = i;
            }
            supplies[idx] = mn;
            for (int i = idx + 1; i < n - it - 1; i++) {
                supplies[i] = supplies[i + 1];
            }
        }
        for (int i = 0; i < m; i++) supplies.pop_back();
        return supplies;
    }
};