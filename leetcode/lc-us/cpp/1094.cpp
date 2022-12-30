#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        int map[1001] = {};
        for (auto &trip: trips) {
            map[trip[1]] += trip[0];
            map[trip[2]] -= trip[0];
        }
        int temp = 0;
        for (int i = 0; i <= 1000; i++) {
            temp += map[i];
            if (temp > capacity) return false;
        }
        return true;
    }
};