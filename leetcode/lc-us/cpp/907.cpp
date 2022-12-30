#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int> &arr) {
        using ll = long long;
        const int MOD = 1e9 + 7;
        int n = (int) arr.size();
        ll res = 0;
        vector<int> left(n, -1), right(n, n);
        stack<int> s, t;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            if (!s.empty()) left[i] = s.top();
            s.push(i);
        }
        for (int i = n - 1; ~i; i--) {
            while (!t.empty() && arr[t.top()] > arr[i]) t.pop();
            if (!t.empty()) right[i] = t.top();
            t.push(i);
        }
        for (int i = 0; i < n; i++) {
            res = (res + (ll) (i - left[i]) * (right[i] - i) * arr[i]) % MOD;
        }
        return (int) res;
    }
};