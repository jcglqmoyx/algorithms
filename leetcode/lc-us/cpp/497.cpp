#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> rectangles;
    vector<int> s;
public:
    Solution(vector<vector<int>> &rects) {
        rectangles = rects;
        for (auto r: rects) {
            int dx = r[2] - r[0] + 1, dy = r[3] - r[1] + 1;
            if (s.empty()) s.push_back(dx * dy);
            else s.push_back(s.back() + dx * dy);
        }
    }

    vector<int> pick() {
        int k = rand() % (s.back() + 1);
        int l = 0, r = (int) s.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (s[mid] >= k) r = mid;
            else l = mid + 1;
        }
        auto rect = rectangles[l];
        int dx = rect[2] - rect[0] + 1, dy = rect[3] - rect[1] + 1;
        return {rect[0] + rand() % dx, rect[1] + rand() % dy};
    }
};