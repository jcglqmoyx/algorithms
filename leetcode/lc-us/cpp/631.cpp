#include <bits/stdc++.h>

using namespace std;

class Excel {
    const int INF = 0x3f3f3f3f;
    int v[26][26];
    int g[26][26][26][26];
    int h, w;

    void process(int r, char c, int i, int j) {
        if (g[r][c][i][j] == INF) {
            g[r][c][i][j] = 1;
        } else {
            g[r][c][i][j]++;
        }
    }

public:
    Excel(int height, char width) {
        this->h = height, this->w = width - 'A' + 1;
        memset(v, 0x3f, sizeof v);
        memset(g, 0x3f, sizeof g);
    }

    void set(int row, char column, int val) {
        row--, column -= 'A';
        memset(g[row][column], 0x3f, sizeof g[row][column]);
        v[row][column] = val;
    }

    int get(int row, char column) {
        row--, column -= 'A';
        if (v[row][column] != INF) return v[row][column];
        int res = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (g[row][column][i][j] != INF) {
                    res += g[row][column][i][j] * get(i + 1, (char) (j + 'A'));
                }
            }
        }
        return res;
    }

    int sum(int row, char column, vector<string> numbers) {
        row--, column -= 'A';
        memset(g[row][column], 0x3f, sizeof g[row][column]);
        v[row][column] = INF;
        for (auto &n: numbers) {
            auto idx = n.find(':');
            if (idx == string::npos) {
                int c = n[0] - 'A', r = stoi(n.substr(1)) - 1;
                process(row, column, r, c);
            } else {
                int c1 = n[0] - 'A', r1 = stoi(n.substr(1, idx - 1)) - 1;
                int c2 = n[idx + 1] - 'A', r2 = stoi(n.substr(idx + 2)) - 1;
                for (int r = r1; r <= r2; r++) {
                    for (int c = c1; c <= c2; c++) {
                        process(row, column, r, c);
                    }
                }
            }
        }
        int res = 0;
        for (int r = 0; r < this->h; r++) {
            for (int c = 0; c < this->w; c++) {
                if (g[row][column][r][c] != INF) {
                    res += g[row][column][r][c] * get(r + 1, (char) (c + 'A'));
                }
            }
        }
        return res;
    }
};