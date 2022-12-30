#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
        int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, direction = 0, max_distance = 0;
        unordered_set<string> obstacle_set;
        for (const vector<int> &obstacle: obstacles) {
            obstacle_set.insert(to_string(obstacle[0]) + '_' + to_string(obstacle[1]));
        }
        for (int command: commands) {
            switch (command) {
                case -2:
                    direction = (direction + 1) % 4;
                    break;
                case -1:
                    direction = (direction + 3) % 4;
                    break;
                default:
                    for (int i = 0; i < command; i++) {
                        int x_next = x + dx[direction];
                        int y_next = y + dy[direction];
                        if (obstacle_set.count(to_string(x_next) + '_' + to_string(y_next))) {
                            break;
                        } else {
                            x = x_next;
                            y = y_next;
                        }
                    }
                    max_distance = max(max_distance, x * x + y * y);
                    break;
            }
        }
        return max_distance;
    }
};