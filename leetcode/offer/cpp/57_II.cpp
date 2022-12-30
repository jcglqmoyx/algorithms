#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> consequences;
        vector<int> consequence;
        int l = 1, r = 2;
        while (l < r) {
            int sum = (r - l + 1) * (l + r) / 2;
            if (sum == target) {
                consequence.clear();
                for (int i = l; i <= r; i++) {
                    consequence.push_back(i);
                }
                consequences.push_back(consequence);
                l++;
            } else if (sum < target) {
                r++;
            } else {
                l++;
            }
        }
        return consequences;
    }
};