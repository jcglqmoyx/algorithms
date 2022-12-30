#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
        stations.push_back({target, 0});
        int n = (int) stations.size();
        int f = 0;
        priority_queue<int> heap;
        for (int i = 1, tot_fuel = startFuel; i <= n; i++) {
            int position = stations[i - 1][0], fuel = stations[i - 1][1];
            while (tot_fuel < position && !heap.empty()) {
                int t = heap.top();
                heap.pop();
                tot_fuel += t;
                f++;
            }
            if (tot_fuel < position) return -1;
            heap.push(fuel);
        }
        return f;
    }
};