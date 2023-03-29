#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int> &satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<>());
        int pre_sum = 0, ans = 0;
        for (int si: satisfaction) {
            if (pre_sum + si > 0) {
                pre_sum += si;
                ans += pre_sum;
            } else {
                break;
            }
        }
        return ans;
    }
};