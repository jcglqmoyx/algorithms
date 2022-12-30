#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience) {
        int n = (int) energy.size();
        int e = initialEnergy, x = initialExperience;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (e <= energy[i]) {
                int t = energy[i] + 1 - e;
                res += t;
                e += t;
            }
            if (x <= experience[i]) {
                int t = experience[i] + 1 - x;
                res += t;
                x += t;
            }
            x += experience[i];
            e -= energy[i];
        }
        return res;
    }
};