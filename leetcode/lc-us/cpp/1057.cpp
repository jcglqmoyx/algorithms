#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes) {
        int n = (int) workers.size(), m = (int) bikes.size();
        map<int, vector<pair<int, int>>> dis2workBike;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int dis = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                dis2workBike[dis].push_back({i, j});
            }
        }
        vector<int> ans(n);
        vector<int> visWork(n), visBike(m);
        for (auto&[dis, workBike]: dis2workBike) {
            for (auto[work, bike]: workBike) {
                if (visWork[work] == 1 || visBike[bike] == 1)continue;
                visWork[work] = 1, visBike[bike] = 1;
                ans[work] = bike;
            }
        }
        return ans;
    }
};