#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        string res;
        int n = (int) s.size();
        vector<char> f(n + 1);
        f[n] = 'z' + 1;
        for (int i = n - 1; i >= 0; i--) f[i] = min(s[i], f[i + 1]);
        stack<char> stk;
        for (int i = 0; i < n; i++) {
            stk.push(s[i]);
            while (!stk.empty() && stk.top() <= f[i + 1]) res.push_back(stk.top()), stk.pop();
        }
        return res;
    }
};