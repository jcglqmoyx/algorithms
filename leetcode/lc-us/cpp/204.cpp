#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<int> primes;
        bool st[n];
        memset(st, 0, sizeof st);
        for (int i = 2; i < n; ++i) {
            if (!st[i]) primes.push_back(i);
            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
                st[i * primes[j]] = true;
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
        return (int) primes.size();
    }
};