#include <bits/stdc++.h>

using namespace std;

class MovingAverage {
    queue<int> arr;
    int n;
    double sum;

public:
    MovingAverage(int size) {
        n = size;
        sum = 0;
    }

    double next(int val) {
        sum += val;
        arr.push(val);
        if (arr.size() > n) {
            sum -= arr.front();
            arr.pop();
        }
        return sum / (int) arr.size();
    }
};