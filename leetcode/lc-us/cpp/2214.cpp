#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumHealth(vector<int> &damage, int armor) {
        using LL = long long;
        int mx = 0;
        LL sum = 0;
        for (int d: damage) {
            mx = max(mx, d);
            sum += d;
        }
        return sum - min(mx, armor) + 1;
    }
};