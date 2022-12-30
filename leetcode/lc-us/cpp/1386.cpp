#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats) {
        unordered_map<int, int> seated;
        int masks[3] = {0b11110000, 0b00111100, 0b00001111};
        for (auto &seat: reservedSeats) {
            int col = seat[1];
            if (col == 1 || col == 10) continue;
            seated[seat[0]] |= 1 << (seat[1] - 2);
        }
        int cnt = 0;
        for (auto[k, v]: seated) {
            for (int mask: masks) {
                if ((mask & v) == 0) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt + (n - (int) seated.size()) * 2;
    }
};