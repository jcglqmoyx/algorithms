#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long putMarbles(vector<int> &weights, int k) {
        int n = (int) weights.size();
        for (int i = 0; i + 1 < n; i++) {
            weights[i] += weights[i + 1];
        }
        weights.pop_back();
        sort(weights.begin(), weights.end());

        long long res = 0;
        for (int i = n - 2; i >= n - k; i--) {
            res += weights[i];
        }
        for (int i = 0; i < k - 1; i++) {
            res -= weights[i];
        }
        return res;
    }
};