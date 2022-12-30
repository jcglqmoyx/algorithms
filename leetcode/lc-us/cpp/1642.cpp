#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<>> q;
        int n = heights.size();
        for (int i = 0; i < n - 1; i++) {
            if (heights[i] < heights[i + 1]) {
                int diff = heights[i + 1] - heights[i];
                q.push(diff);
                if (ladders) {
                    ladders--;
                } else {
                    if (bricks >= q.top()) {
                        bricks -= q.top();
                        q.pop();
                    } else {
                        return i;
                    }
                }
            }
        }
        return n - 1;
    }
};