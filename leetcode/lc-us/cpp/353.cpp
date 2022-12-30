#include <bits/stdc++.h>

using namespace std;

class SnakeGame {
    int w, h;
    int idx, score;
    vector<vector<int>> f;
    deque<pair<int, int>> q;
    unordered_set<string> vis;

public:
    SnakeGame(int width, int height, vector<vector<int>> &food) {
        w = width, h = height;
        idx = score = 0;
        f = food;
        q.emplace_back(0, 0);
        vis.insert("0 0");
    }

    int move(string direction) {
        int x = q.back().first, y = q.back().second;
        switch (direction[0]) {
            case 'U':
                x--;
                break;
            case 'D':
                x++;
                break;
            case 'L':
                y--;
                break;
            case 'R':
                y++;
                break;
            default:
                break;
        }
        vis.erase(to_string(q.front().first) + ' ' + to_string(q.front().second));
        string pos = to_string(x) + ' ' + to_string(y);
        if (x >= h || y >= w || x < 0 || y < 0 || vis.count(pos)) return -1;
        q.emplace_back(x, y);
        vis.insert(pos);
        if (idx < f.size() && x == f[idx][0] && y == f[idx][1]) {
            score++;
            idx++;
            return score;
        }
        q.pop_front();
        return score;
    }
};