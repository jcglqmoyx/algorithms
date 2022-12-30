#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        vector<int> dp(n);
        dp[0] = 1;
        vector<int> pointers(primes.size());
        for (int i = 1; i < n; i++) {
            int min_value = INT32_MAX;
            for (int j = 0; j < primes.size(); j++) {
                long long temp = (long long) dp[pointers[j]] * primes[j];
                if (temp < min_value) {
                    min_value = (int) temp;
                }
            }
            dp[i] = min_value;
            for (int j = 0; j < primes.size(); j++) {
                long long temp = (long long) dp[pointers[j]] * primes[j];
                if (temp == min_value) {
                    pointers[j]++;
                }
            }
        }
        return dp[n - 1];
    }
};