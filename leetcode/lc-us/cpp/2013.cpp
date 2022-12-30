#include <bits/stdc++.h>

using namespace std;

class DetectSquares {
    unordered_map<int, unordered_map<int, int>> row, col;
public:
    DetectSquares() {
    }

    void add(vector<int> point) {
        int r = point[0], c = point[1];
        row[r][c]++, col[c][r]++;
    }

    int count(vector<int> point) {
        int res = 0;
        int r = point[0], c = point[1];
        if (row.count(r) && col.count(c)) {
            for (auto column: row[r]) {
                if (column.first == c) continue;
                int rr = r, cc = column.first;
                int len = abs(column.first - c);
                for (int i = -1; i <= 1; i += 2) {
                    if (row.count(r + len * i) && col.count(cc)) {
                        res += row[rr][cc] * row[r + len * i][cc] * row[r + len * i][c];
                    }
                }
            }
        }
        return res;
    }
};