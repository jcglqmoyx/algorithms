#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double calculateTax(vector<vector<int>> &brackets, int income) {
        double res = 0;
        double prev = 0;
        for (auto &b: brackets) {
            if (income >= b[0]) {
                res += (b[0] - prev) * b[1] / 100.0;
            } else {
                res += (income - prev) * b[1] / 100.0;
                break;
            }
            prev = b[0];
        }
        return res;
    }
};