#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<int, int> memo;
public:
    int minDays(int n) {
        if (n <= 1) return 1;
        if (memo.count(n)) return memo[n];
        return memo[n] = min({n, 1 + n % 3 + minDays(n / 3), 1 + n % 2 + minDays(n >> 1)});
    }
};