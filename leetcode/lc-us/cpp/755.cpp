#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> pourWater(vector<int> &heights, int volume, int k) {
        int n = (int) heights.size();
        while (volume--) {
            heights[k]++;
            bool fallen = false;
            for (int i = k, j = k - 1; j >= 0; j--) {
                if (heights[i] <= heights[j]) break;
                if (heights[i] > heights[j] + 1) {
                    heights[i]--;
                    heights[j]++;
                    fallen = true;
                    i = j;
                }
            }
            if (fallen) continue;
            for (int i = k, j = k + 1; j < n; j++) {
                if (heights[i] <= heights[j]) break;
                if (heights[i] > heights[j] + 1) {
                    heights[i]--;
                    heights[j]++;
                    i = j;
                }
            }
        }
        return heights;
    }
};