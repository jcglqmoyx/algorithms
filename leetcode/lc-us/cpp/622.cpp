#include <bits/stdc++.h>

using namespace std;

class MyCircularQueue {
    int hh, tt;
    int n;
    int a[4000];
public:
    MyCircularQueue(int k) {
        hh = 0, tt = -1;
        n = k;
        memset(a, 0, sizeof a);
    }

    bool enQueue(int value) {
        if (tt - hh + 1 == n) return false;
        a[++tt] = value;
        return true;
    }

    bool deQueue() {
        if (tt < hh) return false;
        hh++;
        return true;
    }

    int Front() {
        if (hh <= tt) return a[hh];
        return -1;
    }

    int Rear() {
        if (hh <= tt) return a[tt];
        return -1;
    }

    bool isEmpty() {
        return hh > tt;
    }

    bool isFull() {
        return tt - hh + 1 == n;
    }
};