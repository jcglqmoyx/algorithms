#include <bits/stdc++.h>

using namespace std;

class Solution {
    stack<int> nums;
    stack<char> op;
    unordered_map<char, int> priority{{'+', 1},
                                      {'-', 1},
                                      {'*', 2},
                                      {'/', 2}};

    void eval() {
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        char c = op.top();
        op.pop();
        switch (c) {
            case '+':
                nums.push(a + b);
                break;
            case '-':
                nums.push(a - b);
                break;
            case '*':
                nums.push(a * b);
                break;
            case '/':
                nums.push(a / b);
                break;
            default:
                break;
        }
    }

public:
    int calculate(string s) {
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (isdigit(c)) {
                int x = 0, j = i;
                while (j < n && isdigit(s[j])) {
                    x = x * 10 + (s[j++] - '0');
                }
                nums.push(x);
                i = j - 1;
            } else if (c == '(') {
                op.push(c);
            } else if (c == ')') {
                while (op.top() != '(') {
                    eval();
                }
                op.pop();
            } else {
                while (!op.empty() && priority[op.top()] >= priority[c]) {
                    eval();
                }
                op.push(c);
            }
        }
        while (!op.empty()) {
            eval();
        }
        return nums.top();
    }
};