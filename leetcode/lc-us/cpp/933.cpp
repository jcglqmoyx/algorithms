#include <bits/stdc++.h>

using namespace std;

class RecentCounter {
    queue<int> calls;
public:
    RecentCounter() {
    }

    int ping(int t) {
        calls.push(t);
        while (t - calls.front() > 3000) {
            calls.pop();
        }
        return (int) calls.size();
    }
};