#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>> &towers, int radius) {
        vector<int> res;
        int max_signal = 0;
        for (int i = 0; i <= 50; i++) {
            for (int j = 0; j <= 50; j++) {
                int signal = 0;
                for (auto &t: towers) {
                    double dist = sqrt((i - t[0]) * (i - t[0]) + (j - t[1]) * (j - t[1]));
                    if (dist <= radius) signal += t[2] / (1 + dist);
                }
                if (signal > max_signal) {
                    max_signal = signal;
                    res = {i, j};
                }
                if (max_signal == 0) {
                    res = {0, 0};
                }
            }
        }
        return res;
    }
};