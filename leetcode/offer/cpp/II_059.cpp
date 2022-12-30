#include <bits/stdc++.h>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int> &nums) {
        m = k;
        for (int num: nums) {
            heap.push(num);
            if (heap.size() > k) heap.pop();
        }
    }

    int add(int val) {
        heap.push(val);
        if (heap.size() > m) heap.pop();
        return heap.top();
    }

private:
    int m;
    priority_queue<int, vector<int>, greater<>> heap;
};