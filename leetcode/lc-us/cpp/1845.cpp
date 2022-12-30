#include <bits/stdc++.h>

using namespace std;

class SeatManager {
    priority_queue<int, vector<int>, greater<>> available, unavailable;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) available.push(i);
    }

    int reserve() {
        int t = available.top();
        if (!unavailable.empty() && t == unavailable.top()) {
            while (available.top() == unavailable.top()) {
                t = available.top();
                available.pop();
            }
            return t;
        } else {
            available.pop();
            return t;
        }
    }

    void unreserve(int seatNumber) {
        available.push(seatNumber);
    }
};