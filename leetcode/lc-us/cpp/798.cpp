#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bestRotation(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> move(n);
        for (int i = 0; i < n; i++) {
            move[(i + 1) % n]++;
            move[(n - (nums[i] - i) + 1) % n]--;
            if (nums[i] <= i) {
                move[0]++;
            }
        }
        int res = -1, max_score = 0, score = 0;
        for (int i = 0; i < n; i++) {
            score += move[i];
            if (score > max_score) max_score = score, res = i;
        }
        return res;
    }
};