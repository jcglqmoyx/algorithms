#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dietPlanPerformance(vector<int> &calories, int k, int lower, int upper) {
        int points = 0;
        int t = 0;
        int prev = calories[0];
        for (int i = 0; i < k; i++) t += calories[i];
        if (t > upper) points++;
        else if (t < lower)points--;
        for (int i = 1; i <= calories.size() - k; i++) {
            t -= prev;
            t += calories[i + k - 1];
            prev = calories[i];
            if (t > upper) points++;
            else if (t < lower) points--;
        }
        return points;
    }
};