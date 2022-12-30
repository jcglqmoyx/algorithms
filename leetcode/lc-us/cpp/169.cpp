#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int res = 0, cnt = 0;
        for (int x: nums) {
            if (x == res) cnt++;
            else cnt--;
            if (cnt < 0) {
                cnt = 1;
                res = x;
            }
        }
        return res;
    }
};