#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>> &matrix) {
        long long sum = 0, cnt = 0;
        int mn = INT32_MAX;
        for (auto &r: matrix) {
            for (int x: r) {
                if (x <= 0) cnt++;
                sum += abs(x);
                mn = min(mn, abs(x));
            }
        }
        if (cnt & 1) sum -= mn * 2;
        return sum;
    }
};