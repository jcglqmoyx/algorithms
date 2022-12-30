#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        for (auto &token: tokens) {
            if (is_operator(token)) {
                int y = stk.top();
                stk.pop();
                int x = stk.top();
                stk.pop();
                stk.push(calculate(x, y, token));
            } else stk.push(stoi(token));
        }
        return stk.top();
    }

private:
    int calculate(int x, int y, string &operation) {
        if (operation == "+") return x + y;
        else if (operation == "-") return x - y;
        else if (operation == "*") return x * y;
        else return x / y;
    }

    bool is_operator(string &token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
};