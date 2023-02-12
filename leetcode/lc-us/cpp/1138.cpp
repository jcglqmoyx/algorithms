#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string alphabetBoardPath(string target) {
        int x = 0, y = 0;
        string res;
        for (char c: target) {
            int nx = (c - 'a') / 5;
            int ny = (c - 'a') % 5;
            if (nx < x) res.append(x - nx, 'U');
            if (ny < y) res.append(y - ny, 'L');
            if (nx > x) res.append(nx - x, 'D');
            if (ny > y) res.append(ny - y, 'R');
            res.push_back('!');
            x = nx;
            y = ny;
        }
        return res;
    }
};