#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        const int mx = 1e6;
        vector<int> prime;
        bool st[mx + 1] = {};
        for (int i = 2; i <= mx; i++) {
            if (!st[i]) prime.push_back(i);
            for (int j = 0; prime[j] * i <= mx; j++) {
                st[prime[j] * i] = true;
                if (i % prime[j] == 0) break;
            }
        }
        prime.push_back(mx + 1);
        prime.push_back(mx + 1);
        vector<int> res = {-1, -1};
        int min_diff = mx;
        for (auto i = lower_bound(prime.begin(), prime.end(), left) - prime.begin(); prime[i + 1] <= right; i++) {
            int diff = prime[i + 1] - prime[i];
            if (diff < min_diff) {
                min_diff = diff;
                res[0] = prime[i], res[1] = prime[i + 1];
            }
        }
        return res;
    }
};