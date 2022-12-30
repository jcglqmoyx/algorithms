#include <bits/stdc++.h>

using namespace std;

class MaxQueue {
    queue<int> q;
    deque<int> dq;
public:
    MaxQueue() {
    }

    int max_value() {
        return dq.empty() ? -1 : dq.front();
    }

    void push_back(int value) {
        while (!dq.empty() && dq.back() < value) {
            dq.pop_back();
        }
        dq.push_back(value);
        q.push(value);
    }

    int pop_front() {
        if (q.empty()) return -1;
        if (q.front() == dq.front()) {
            dq.pop_front();
        }
        int front = q.front();
        q.pop();
        return front;
    }
};