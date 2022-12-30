#include <bits/stdc++.h>

using namespace std;

class MinStack {
    stack<int> stk, min_stk;
public:
    MinStack() {
        min_stk.push(INT32_MAX);
    }

    void push(int x) {
        stk.push(x);
        min_stk.push(min(x, min_stk.top()));
    }

    void pop() {
        stk.pop();
        min_stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top();
    }
};