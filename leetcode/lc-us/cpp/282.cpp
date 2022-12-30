#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    using LL = long long;

    int n, _target;
    string _num, expr;
    vector<string> ans;

    void dfs(int i, LL cur, LL last) {
        if (i == n) {
            if (cur == _target) ans.push_back(expr);
            return;
        }
        int len = (int) expr.size();
        LL val = 0;
        if (i) expr.push_back(0);
        for (int j = i; j < n && (j == i || _num[i] != '0'); j++) {
            expr.push_back(_num[j]);
            val = val * 10 + _num[j] - '0';
            if (!i) dfs(j + 1, val, val);
            else {
                expr[len] = '+', dfs(j + 1, cur + val, val);
                expr[len] = '-', dfs(j + 1, cur - val, -val);
                expr[len] = '*', dfs(j + 1, cur - last + last * val, last * val);
            }
        }
        expr.resize(len);
    }

public:
    vector<string> addOperators(string num, int target) {
        n = (int) num.size(), _num = num, _target = target;
        dfs(0, 0, 0);
        return ans;
    }
};