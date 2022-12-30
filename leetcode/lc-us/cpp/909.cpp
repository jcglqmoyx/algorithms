#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n, target;

    pair<int, int> get_position(int x) {
        int row = (x - 1) / n;
        int col;
        if (row & 1) col = (n - x % n) % n;
        else col = (x + n - 1) % n;
        return {n - row - 1, col};
    }

public:
    int snakesAndLadders(vector<vector<int>> &board) {
        n = (int) board.size(), target = n * n;
        unordered_map<int, int> dist;
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int move = 1; move <= 6; move++) {
                int des = t + move;
                if (des > target) break;
                auto[x, y] = get_position(des);
                if (board[x][y] != -1) {
                    des = board[x][y];
                }
                if (des == target) return dist[t] + 1;
                if (!dist.count(des)) {
                    dist[des] = dist[t] + 1;
                    q.push(des);
                }
            }
        }
        return -1;
    }
};