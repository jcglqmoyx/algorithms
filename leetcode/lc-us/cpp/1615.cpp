#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads) {
        vector<vector<bool>> connect(n, vector<bool>(n, false));
        vector<int> degree(n);
        for (auto road: roads) {
            int x = road[0], y = road[1];
            connect[x][y] = true;
            connect[y][x] = true;
            degree[x]++;
            degree[y]++;
        }

        int first = -1, second = -2;
        vector<int> first_arr, second_arr;
        for (int i = 0; i < n; ++i) {
            if (degree[i] > first) {
                second = first;
                second_arr = first_arr;
                first = degree[i];
                first_arr.clear();
                first_arr.emplace_back(i);
            } else if (degree[i] == first) {
                first_arr.emplace_back(i);
            } else if (degree[i] > second) {
                second_arr.clear();
                second = degree[i];
                second_arr.emplace_back(i);
            } else if (degree[i] == second) {
                second_arr.emplace_back(i);
            }
        }
        if (first_arr.size() == 1) {
            int u = first_arr[0];
            for (int v: second_arr) {
                if (!connect[u][v]) {
                    return first + second;
                }
            }
            return first + second - 1;
        } else {
            int m = (int) roads.size();
            if (first_arr.size() * (first_arr.size() - 1) / 2 > m) {
                return first * 2;
            }
            for (int u: first_arr) {
                for (int v: first_arr) {
                    if (u != v && !connect[u][v]) {
                        return first * 2;
                    }
                }
            }
            return first * 2 - 1;
        }
    }
};