#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        using LL = long long;

        if (num % 3 == 0) {
            LL x = num / 3;
            return {x - 1, x, x + 1};
        }
        return {};
    }
};