#include <bits/stdc++.h>

using namespace std;

class Solution {
    stack<vector<int> > num;
    stack<char> op;

    int get_min(vector<int> &v) {
        int res = INT32_MAX;
        for (int x: v) {
            res = min(res, x);
        }
        return res;
    }

    void eval() {
        auto b = num.top();
        num.pop();
        auto a = num.top();
        num.pop();
        char c = op.top();
        op.pop();
        if (c == '&') {
            vector<int> v0 = {a[0] + b[0], a[0] + b[1], a[1] + b[0], a[0] + b[0] + 1};
            vector<int> v1 = {a[1] + b[1], a[0] + b[1] + 1, a[1] + b[0] + 1, a[1] + b[1] + 1};
            num.push({get_min(v0), get_min(v1)});
        } else if (c == '|') {
            vector<int> v0 = {a[0] + b[0], a[0] + b[1] + 1, a[1] + b[0] + 1, a[0] + b[0] + 1};
            vector<int> v1 = {a[1] + b[1], a[0] + b[1], a[1] + b[0], a[1] + b[1] + 1};
            num.push({get_min(v0), get_min(v1)});
        }
    }

public:
    int minOperationsToFlip(string expression) {
        for (char c: expression) {
            if (c == '0') num.push({0, 1});
            else if (c == '1') num.push({1, 0});
            else if (c == '(') op.push(c);
            else if (c == ')') {
                while (op.top() != '(') eval();
                op.pop();
            } else {
                while (!op.empty() && op.top() != '(') eval();
                op.push(c);
            }
        }
        while (!op.empty()) eval();
        return max(num.top()[0], num.top()[1]);
    }
};