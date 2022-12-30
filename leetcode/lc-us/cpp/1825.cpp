#include <bits/stdc++.h>

using namespace std;

class MKAverage {
    using LL = long long;

    int m, k;
    LL sum;
    multiset<int> low, mid, high;
    queue<int> q;
public:
    MKAverage(int _m, int _k) {
        sum = 0;
        m = _m, k = _k;
    }

    void addElement(int num) {
        q.push(num);
        if (!low.empty() && *low.rbegin() > num) {
            low.insert(num);
        } else if (!high.empty() && *high.begin() < num) {
            high.insert(num);
        } else {
            mid.insert(num);
            sum += num;
        }
        while (low.size() > k) {
            mid.insert(*low.rbegin());
            sum += *low.rbegin();
            low.erase(low.find(*low.rbegin()));
        }
        while (high.size() > k) {
            mid.insert(*high.begin());
            sum += *high.begin();
            high.erase(high.begin());
        }
        if (q.size() > m) {
            int t = q.front();
            q.pop();
            if (low.find(t) != low.end()) {
                low.erase(low.find(t));
            } else if (high.find(t) != high.end()) {
                high.erase(high.find(t));
            } else {
                sum -= t;
                mid.erase(mid.find(t));
            }
        }
        if (q.size() == m) {
            while (low.size() < k) {
                low.insert(*mid.begin());
                sum -= *mid.begin();
                mid.erase(mid.begin());
            }
            while (high.size() < k) {
                high.insert(*mid.rbegin());
                sum -= *mid.rbegin();
                mid.erase(mid.find(*mid.rbegin()));
            }
        }
    }

    int calculateMKAverage() {
        if (q.size() < m) return -1;
        return (int) (sum / (m - k * 2));
    }
};