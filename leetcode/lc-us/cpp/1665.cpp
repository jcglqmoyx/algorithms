#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>> &tasks) {
        sort(tasks.begin(), tasks.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        int res = 0, energy = 0;
        for (auto &t: tasks) {
            if (energy < t[1]) res += t[1] - energy, energy = t[1];
            energy -= t[0];
        }
        return res;
    }
};