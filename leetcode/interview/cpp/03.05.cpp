#include <bits/stdc++.h>

using namespace std;

class SortedStack {
    stack<int> stk, auxiliary;
public:
    SortedStack() {
    }

    void push(int val) {
        while (!stk.empty() && val > stk.top()) {
            auxiliary.push(stk.top());
            stk.pop();
        }
        stk.push(val);
        while (!auxiliary.empty()) {
            stk.push(auxiliary.top());
            auxiliary.pop();
        }
    }

    void pop() {
        if (!stk.empty()) stk.pop();
    }

    int peek() {
        if (stk.empty()) return -1;
        return stk.top();
    }

    bool isEmpty() {
        return stk.empty();
    }
};