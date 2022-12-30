#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<>> min_q;
public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (max_q.size() == min_q.size()) {
            min_q.push(num);
            max_q.push(min_q.top());
            min_q.pop();
        } else {
            max_q.push(num);
            min_q.push(max_q.top());
            max_q.pop();
        }
    }

    double findMedian() {
        if (min_q.size() != max_q.size()) return max_q.top();
        else return (min_q.top() + max_q.top()) / 2.0;
    }
};