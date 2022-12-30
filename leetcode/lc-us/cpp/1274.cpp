#include <bits/stdc++.h>

using namespace std;

class Sea {
public:
    bool hasShips(vector<int> topRight, vector<int> bottomLeft);
};

class Solution {
    int find(Sea &sea, vector<int> top_right, vector<int> bottom_left) {
        int x1 = bottom_left[0], x2 = top_right[0], y1 = bottom_left[1], y2 = top_right[1];
        if (x1 > x2 || y1 > y2) return 0;
        if (!sea.hasShips(top_right, bottom_left)) return 0;
        if (x1 == x2 && y1 == y2) return 1;
        int xm = (x1 + x2) >> 1, ym = (y1 + y2) >> 1;
        int cnt = find(sea, {xm, ym}, {x1, y1});
        cnt += find(sea, {xm, y2}, {x1, ym + 1});
        cnt += find(sea, {x2, ym}, {xm + 1, y1});
        cnt += find(sea, {x2, y2}, {xm + 1, ym + 1});
        return cnt;
    }

public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        return find(sea, move(topRight), move(bottomLeft));
    }
};