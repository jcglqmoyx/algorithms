#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    pair<int, int> sub(pair<int, int> a, pair<int, int> b) {
        return make_pair(a.first - b.first, a.second - b.second);
    }

    int cross(pair<int, int> a, pair<int, int> b) {
        return a.first * b.second - a.second * b.first;
    }

public:
    vector<int> visitOrder(vector<vector<int> > &points, string dir) {
        int n = (int) points.size();
        vector<bool> used(n, false);
        vector<pair<int, int> > point;
        vector<int> order;

        for (int i = 0; i < n; ++i) {
            point.emplace_back(points[i][0], points[i][1]);
        }

        int start = 0;
        for (int i = 1; i < n; ++i) {
            if (point[i] < point[start]) {
                start = i;
            }
        }
        used[start] = true;
        order.push_back(start);

        for (char i: dir) {
            int next = -1;
            if (i == 'L') {
                for (int j = 0; j < n; ++j) {
                    if (!used[j]) {
                        if (next == -1 || cross(sub(point[next], point[start]), sub(point[j], point[start])) < 0) {
                            next = j;
                        }
                    }
                }
            } else if (i == 'R') {
                for (int j = 0; j < n; ++j) {
                    if (!used[j]) {
                        if (next == -1 || cross(sub(point[next], point[start]), sub(point[j], point[start])) > 0) {
                            next = j;
                        }
                    }
                }
            }
            used[next] = true;
            order.push_back(next);
            start = next;
        }
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                order.push_back(i);
            }
        }
        return order;
    }
};