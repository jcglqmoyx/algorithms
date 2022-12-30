#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        int cnt[n];
        memset(cnt, 0, sizeof cnt);

        sort(meetings.begin(), meetings.end());
        set<int> S;
        for (int i = 0; i < n; i++) {
            S.insert(i);
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> heap;

        long long cur = 0;
        for (auto &meeting: meetings) {
            long long start = meeting[0], end = meeting[1], duration = end - start;
            cur = max(cur, start);

            while (!heap.empty() && heap.top().first <= cur) {
                S.insert(heap.top().second);
                heap.pop();
            }

            if (!S.empty()) {
                int room = *S.begin();
                S.erase(S.begin());
                heap.push({cur + duration, room});
                cnt[room]++;
            } else {
                auto t = heap.top();
                heap.pop();
                cur = t.first;
                heap.push({cur + duration, t.second});
                cnt[t.second]++;
            }
        }

        int mx = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > mx) {
                mx = cnt[i];
                res = i;
            }
        }
        return res;
    }
};