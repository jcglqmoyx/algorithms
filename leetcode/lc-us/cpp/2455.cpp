#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int averageValue(vector<int> &nums) {
        int cnt = 0, sum = 0;
        for (int x: nums) {
            if (x % 6 == 0) {
                cnt++;
                sum += x;
            }
        }
        if (!cnt) return 0;
        return sum / cnt;
    }
};