#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int MOUSE_TURN = 0, CAT_TURN = 1;
    const int DRAW = 0, MOUSE_WIN = 1, CAT_WIN = 2;
    vector<vector<int>> graph;
    vector<vector<vector<int>>> degrees;
    vector<vector<vector<int>>> results;

    vector<tuple<int, int, int>> get_prev_states(int mouse, int cat, int turn) {
        vector<tuple<int, int, int>> prev_states;
        int prevTurn = turn == MOUSE_TURN ? CAT_TURN : MOUSE_TURN;
        if (prevTurn == MOUSE_TURN) {
            for (int &prev: graph[mouse]) {
                prev_states.emplace_back(prev, cat, prevTurn);
            }
        } else {
            for (int &prev: graph[cat]) {
                if (prev != 0) {
                    prev_states.emplace_back(mouse, prev, prevTurn);
                }
            }
        }
        return prev_states;
    }

public:
    int catMouseGame(vector<vector<int>> &graph) {
        int n = (int) graph.size();
        this->graph = graph;
        this->degrees = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(2)));
        this->results = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(2)));
        queue<tuple<int, int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                degrees[i][j][MOUSE_TURN] = (int) graph[i].size();
                degrees[i][j][CAT_TURN] = (int) graph[j].size();
            }
        }
        for (int node: graph[0]) {
            for (int i = 0; i < n; i++) {
                degrees[i][node][CAT_TURN]--;
            }
        }
        for (int j = 1; j < n; j++) {
            results[0][j][MOUSE_TURN] = MOUSE_WIN;
            results[0][j][CAT_TURN] = MOUSE_WIN;
            q.emplace(0, j, MOUSE_TURN);
            q.emplace(0, j, CAT_TURN);
        }
        for (int i = 1; i < n; i++) {
            results[i][i][MOUSE_TURN] = CAT_WIN;
            results[i][i][CAT_TURN] = CAT_WIN;
            q.emplace(i, i, MOUSE_TURN);
            q.emplace(i, i, CAT_TURN);
        }
        while (!q.empty()) {
            auto[mouse, cat, turn] = q.front();
            q.pop();
            int res = results[mouse][cat][turn];
            vector<tuple<int, int, int>> prev_states = get_prev_states(mouse, cat, turn);
            for (auto &[prevMouse, prevCat, prevTurn]: prev_states) {
                if (results[prevMouse][prevCat][prevTurn] == DRAW) {
                    bool win = (res == MOUSE_WIN && prevTurn == MOUSE_TURN) || (res == CAT_WIN && prevTurn == CAT_TURN);
                    if (win) {
                        results[prevMouse][prevCat][prevTurn] = res;
                        q.emplace(prevMouse, prevCat, prevTurn);
                    } else if (--degrees[prevMouse][prevCat][prevTurn] == 0) {
                        int loseResult = prevTurn == MOUSE_TURN ? CAT_WIN : MOUSE_WIN;
                        results[prevMouse][prevCat][prevTurn] = loseResult;
                        q.emplace(prevMouse, prevCat, prevTurn);
                    }
                }
            }
        }
        return results[1][2][MOUSE_TURN];
    }
};