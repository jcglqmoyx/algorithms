#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distinctPrimeFactors(vector<int> &nums) {
        unordered_set<int> S;
        for (int x: nums) {
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    while (x % i == 0) {
                        x /= i;
                    }
                    S.insert(i);
                }
            }
            if (x > 1) S.insert(x);
        }
        return (int) S.size();
    }
};