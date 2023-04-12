#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y, i{};

    explicit Point(int x = 0, int y = 0) : x(x), y(y) {}
};

struct cmp_x {
    bool operator()(const Point &a, const Point &b) const {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

struct cmp_y {
    bool operator()(const Point &a, const Point &b) const { return a.y < b.y; }
};

class Solution {
public:
    vector<int> beautifulPair(vector<int> &nums1, vector<int> &nums2) {
        int n = (int) nums1.size();
        vector<int> ans(2, n);
        map<pair<int, int>, int> mp;
        vector<Point> a(n);
        for (int i = 0; i < n; i++) {
            if (mp.find(make_pair(nums1[i], nums2[i])) != mp.end()) {
                auto i0 = mp[{nums1[i], nums2[i]}], i1 = i;
                if (i0 < ans[0] || i0 == ans[0] && i1 < ans[1]) {
                    ans[0] = i0;
                    ans[1] = i1;
                }
            } else {
                mp[{nums1[i], nums2[i]}] = i;
            }
            a[i].x = nums1[i];
            a[i].y = nums2[i];
            a[i].i = i;
        }
        if (ans[0] < n && ans[1] < n) {
            return ans;
        }

        sort(a.begin(), a.end(), cmp_x());
        int mn = INT_MAX;
        multiset<Point, cmp_y> s;
        for (int i = 0, l = 0; i < n; i++) {
            while (l < i && a[i].x - a[l].x > mn) s.erase(s.find(a[l++]));
            for (auto it = s.lower_bound(Point(a[i].x, a[i].y - mn)); it != s.end() && it->y - a[i].y <= mn; it++) {
                auto p1 = *it, p2 = a[i];
                auto d = abs(p1.x - p2.x) + abs(p1.y - p2.y);
                auto i0 = min(p1.i, p2.i), i1 = max(p1.i, p2.i);
                if (d < mn || d == mn && i0 < ans[0] || d == mn && i0 == ans[0] && i1 < ans[1]) {
                    mn = d;
                    ans[0] = i0;
                    ans[1] = i1;
                }
            }
            s.insert(a[i]);
        }
        return ans;
    }
};