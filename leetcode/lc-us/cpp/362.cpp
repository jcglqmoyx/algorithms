#include <bits/stdc++.h>

using namespace std;

class HitCounter {
    deque<int> hits;
public:
    HitCounter() {
    }

    void hit(int timestamp) {
        hits.push_back(timestamp);
    }

    int getHits(int timestamp) {
        while (!hits.empty() && hits.front() + 300 <= timestamp) {
            hits.pop_front();
        }
        return hits.size();
    }
};