#include <bits/stdc++.h>

using namespace std;

class MyStack {
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int r = q1.front();
        q1.pop();
        return r;
    }

    /** Get the top element. */
    int top() {
        int r = q1.front();
        return r;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};