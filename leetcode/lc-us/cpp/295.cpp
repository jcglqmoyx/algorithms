#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
    priority_queue<int, vector<int>, greater<>> min_heap;
    priority_queue<int> max_heap;
public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (min_heap.size() == max_heap.size()) {
            min_heap.push(num);
            max_heap.push(min_heap.top());
            min_heap.pop();
        } else {
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    double findMedian() {
        int m = (int) min_heap.size(), n = (int) max_heap.size();
        if ((m + n) % 2 == 0) {
            return (double) (min_heap.top() + max_heap.top()) / 2;
        } else {
            return (double) max_heap.top();
        }
    }
};