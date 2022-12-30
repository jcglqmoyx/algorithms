#include <bits/stdc++.h>

using namespace std;

class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<>> q;
public:
    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (int num: nums) {
            q.push(num);
            if (q.size() > this->k) {
                q.pop();
            }
        }
    }

    int add(int val) {
        this->q.push(val);
        if (this->q.size() > this->k) {
            this->q.pop();
        }
        return this->q.top();
    }
};