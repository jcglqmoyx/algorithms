#include <bits/stdc++.h>

using namespace std;

class MovingAverage {
public:
    MovingAverage(int size) {
        k = size;
    }

    double next(int val) {
        dq.push_back(val);
        sum += val;
        if (dq.size() > k) {
            sum -= dq.front();
            dq.pop_front();
        }
        return sum / (int) dq.size();
    }

private:
    int k;
    double sum = 0;
    deque<double> dq;
};