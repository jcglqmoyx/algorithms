#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalStrength(vector<int> &strength) {
        using LL = long long;
        const int MOD = 1e9 + 7;

        int n = (int) strength.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && strength[stk.top()] >= strength[i]) stk.pop();
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }
        while (!stk.empty()) stk.pop();
        for (int i = n - 1; ~i; i--) {
            while (!stk.empty() && strength[stk.top()] > strength[i]) stk.pop();
            if (!stk.empty()) right[i] = stk.top();
            stk.push(i);
        }

        vector<int> s = strength;
        for (int i = 1; i < n; i++) s[i] = (s[i] + s[i - 1]) % MOD;
        vector<int> ss = s;
        for (int i = 1; i < n; i++) ss[i] = (ss[i] + ss[i - 1]) % MOD;
        auto get = [&](int low, int high) {
            if (high < 0) return 0;
            else if (low < 0) return ss[high];
            else return ss[high] - ss[low];
        };

        LL res = 0;
        for (int i = 0; i < n; i++) {
            int l = left[i] + 1, r = right[i] - 1;
            LL t = ((LL) get(i - 1, r) * (i - l + 1)) % MOD;
            t -= ((LL) get(l - 2, i - 1) * (r - i + 1)) % MOD;
            t = t * strength[i] % MOD;
            res = (res + t + MOD) % MOD;
        }
        return (int) res;
    }
};