#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
        int m = (int) rolls.size(), sum = mean * (m + n) - accumulate(rolls.begin(), rolls.end(), 0);
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = sum / n;
        }
        int cnt = sum - sum / n * n;
        for (int i = 0; i < cnt; i++) res[i]++;
        for (int i = 0; i < n; i++) {
            if (res[i] < 1 || res[i] > 6) return {};
        }
        return res;
    }
};