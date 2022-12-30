#include <bits/stdc++.h>

using namespace std;

class RecentCounter {
public:
    RecentCounter() {
    }

    int ping(int t) {
        times.push_back(t);
        int earliest = t - 3000;
        return (int) (times.size() - (lower_bound(times.begin(), times.end(), earliest) - times.begin()));
    }

private:
    vector<int> times;
};