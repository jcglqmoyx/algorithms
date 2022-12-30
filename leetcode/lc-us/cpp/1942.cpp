#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

class Solution {
    using PII = pair<int, int>;
    using VI = vector<int>;

    struct cmp {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        }
    };

public:
    int smallestChair(vector<vector<int>> &times, int targetFriend) {
        vector<bool> st(1e5 + 5, false);
        int arrival_time = times[targetFriend][0];
        sort(times.begin(), times.end());

        priority_queue<PII, vector<PII>, cmp> heap;
        priority_queue<int, VI, greater<>> min_seat;

        int mn = -1;
        int number = -1;
        int res;
        for (auto &t: times) {
            while (!heap.empty() && heap.top().x <= t[0]) {
                min_seat.push(heap.top().y);
                heap.pop();
            }
            if (!min_seat.empty()) {
                mn = min_seat.top();
                min_seat.pop();
                if (t[0] == arrival_time) {
                    res = mn;
                    break;
                }
                heap.push({t[1], mn});
            } else {
                number++;
                heap.push({t[1], number});
                if (t[0] == arrival_time) {
                    res = number;
                    break;
                }
            }
        }
        return res;
    }
};