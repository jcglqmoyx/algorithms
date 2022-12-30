#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;

    LL get(int x, int y) {
        return (LL) x * 100000 + y;
    }

public:
    vector<string> printKMoves(int K) {
        int M[128][2];
        M['U'][0] = -1, M['U'][1] = 0;
        M['R'][0] = 0, M['R'][1] = 1;
        M['D'][0] = 1, M['D'][1] = 0;
        M['L'][0] = 0, M['L'][1] = -1;
        char d[4] = {'R', 'D', 'L', 'U'};
        unordered_set<LL> S;
        int x = 0, y = 0;
        char direction = 'R';
        int dd = 0;
        int min_x = 0, min_y = 0, max_x = 0, max_y = 0;
        for (int i = 0; i < K; i++) {
            LL pos = get(x, y);
            if (!S.count(pos)) {
                S.insert(pos);
                dd = (dd + 1) % 4;
            } else {
                S.erase(pos);
                dd = (dd + 3) % 4;
            }
            direction = d[dd];
            x += M[direction][0], y += M[direction][1];
            min_x = min(min_x, x), min_y = min(min_y, y), max_x = max(max_x, x), max_y = max(max_y, y);
        }
        int n = max_x - min_x + 1, m = max_y - min_y + 1;
        vector<string> res(n, string(m, '_'));
        for (int i = min_x; i <= max_x; i++) {
            for (int j = min_y; j <= max_y; j++) {
                if (i == x && j == y) {
                    res[i - min_x][j - min_y] = direction;
                } else {
                    LL pos = get(i, j);
                    if (!S.count(pos)) {
                        res[i - min_x][j - min_y] = '_';
                    } else {
                        res[i - min_x][j - min_y] = 'X';
                    }
                }
            }
        }
        return res;
    }
};