#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        unordered_map<string, int> f;
        function<int(int, int)> dp = [&](int depth, int num) -> int {
            if (!num) return -1;
            string state = to_string(depth) + ' ' + to_string(num);
            if (f.count(state)) return f[state];
            int cost = depth ? depth : 2;
            if (num == 1) return f[state] = cost - 1;
            int q = num / x, r = num % x;
            if (!r) f[state] = dp(depth + 1, q);
            else f[state] = min(dp(depth + 1, q) + r * cost, dp(depth + 1, q + 1) + (x - r) * cost);
            return f[state];
        };
        return dp(0, target);
    }
};