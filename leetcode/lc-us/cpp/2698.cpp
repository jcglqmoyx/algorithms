#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool dfs(string &s, int u, int sum, int target) {
        if (u == s.size()) return sum == target;
        for (int j = u, x = 0; j < s.size(); j++) {
            x = x * 10 + s[j] - '0';
            if (sum + x > target) break;
            if (dfs(s, j + 1, sum + x, target)) return true;
        }
        return false;
    }

public:
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int j = i * i;
            string s = to_string(j);
            if (dfs(s, 0, 0, i)) res += j;
        }
        return res;
    }
};