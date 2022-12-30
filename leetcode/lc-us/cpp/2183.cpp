#include <bits/stdc++.h>

using namespace std;

class Solution {
    int gcd(int x, int y) {
        return x % y == 0 ? y : gcd(y, x % y);
    }

public:
    long long countPairs(vector<int> &nums, int k) {
        using LL = long long;

        vector<int> factors;
        for (int i = 1; i * i <= k; i++) {
            if (k % i == 0) {
                factors.push_back(i);
                if (i * i < k) factors.push_back(k / i);
            }
        }
        LL res = 0;
        unordered_map<int, int> cnt;
        for (int num: nums) {
            res += cnt[k / gcd(num, k)];
            for (int factor: factors) {
                if (num % factor == 0) {
                    cnt[factor]++;
                }
            }
        }
        return res;
    }
};