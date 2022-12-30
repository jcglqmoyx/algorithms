#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (i != n / i) {
                    factors.push_back(n / i);
                }
            }
        }
        if (k > factors.size()) return -1;
        sort(factors.begin(), factors.end());
        return factors[k - 1];
    }
};