#include <bits/stdc++.h>

using namespace std;

struct Node {
    char val;
    Node *left;
    Node *right;

    Node() : val(' '), left(nullptr), right(nullptr) {}

    Node(char x) : val(x), left(nullptr), right(nullptr) {}

    Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    Node *expTree(string s) {
        unordered_map<char, int> pr = {{'+', 1},
                                       {'-', 1},
                                       {'*', 2},
                                       {'/', 2}};
        stack<Node *> nums;
        stack<char> ops;
        auto eval = [&]() {
            auto x = nums.top();
            nums.pop();
            auto y = nums.top();
            nums.pop();
            auto op = ops.top();
            ops.pop();
            nums.push(new Node(op, y, x));
        };
        for (char c: s) {
            if (isdigit(c)) nums.push(new Node(c));
            else {
                if (c == '(') ops.push(c);
                else if (c == ')') {
                    while (ops.top() != '(') eval();
                    ops.pop();
                } else {
                    while (!ops.empty() && pr[ops.top()] >= pr[c]) eval();
                    ops.push(c);
                }
            }
        }
        while (!ops.empty()) eval();
        return nums.top();
    }
};