#include <bits/stdc++.h>

using namespace std;

class Solution {
    static int get_distance(int a, int b, int x, int y) {
        return abs(a - x) + abs(b - y);
    }

public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> cells(rows * cols, vector<int>(2));
        unordered_map<int, vector<vector<int>>> map;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int distance = get_distance(i, j, rCenter, cCenter);
                map[distance].push_back({i, j});
            }
        }
        for (int distance = 0, index = 0; distance <= 200; distance++) {
            if (map.count(distance)) {
                for (const vector<int> &point: map[distance]) {
                    cells[index++] = point;
                }
            }
        }
        return cells;
    }
};