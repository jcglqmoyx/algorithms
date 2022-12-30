#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumBooks(vector<int> &books) {
        using LL = long long;
        int n = (int) books.size();
        LL res = 0;
        stack<int> stk;
        vector<LL> f(n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && books[stk.top()] - stk.top() >= books[i] - i) stk.pop();
            if (stk.empty()) {
                if (books[i] - i < 0) {
                    f[i] = max(f[i], (LL) (books[i] + 1) * books[i] / 2);
                } else {
                    f[i] = (LL) (books[i] + books[i] - i) * (i + 1) / 2;
                }
            } else {
                f[i] = (LL) (books[i] + books[i] - (i - stk.top() - 1)) * (i - stk.top()) / 2 + f[stk.top()];
            }
            res = max(res, f[i]);
            stk.push(i);
        }
        return res;
    }
};