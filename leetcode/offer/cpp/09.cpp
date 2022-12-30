#include <bits/stdc++.h>

using namespace std;

class CQueue {
public:
    CQueue() {
    }

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if (stack1.empty() && stack2.empty()) return -1;
        int top;
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        top = stack2.top();
        stack2.pop();
        return top;
    }

private:
    stack<int> stack1, stack2;
};