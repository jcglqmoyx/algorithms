#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries) {
        const int INF = 1e8;
        struct T {
            int type;
            int id, size;
            int idx;

            bool operator<(const T &t) const {
                if (size == t.size) return type < t.type;
                return size > t.size;
            }
        };
        int n = (int) rooms.size(), m = (int) queries.size();

        vector<T> v;
        v.reserve(n + m);
        for (int i = 0; i < n; i++) {
            v.push_back({0, rooms[i][0], rooms[i][1], i});
        }
        for (int i = 0; i < m; i++) {
            v.push_back({1, queries[i][0], queries[i][1], i});
        }
        sort(v.begin(), v.end());
        set<int> S;
        vector<int> res(m, -1);
        for (const auto &t: v) {
            if (t.type == 0) S.insert(t.id);
            else {
                int dist = INT32_MAX;
                auto it = S.lower_bound(t.id);
                if (it != S.end() && *it - t.id < dist) {
                    dist = *it - t.id;
                    res[t.idx] = *it;
                }
                if (it == S.begin()) continue;
                it--;
                if (t.id - *it <= dist) {
                    res[t.idx] = *it;
                }
            }
        }
        return res;
    }
};