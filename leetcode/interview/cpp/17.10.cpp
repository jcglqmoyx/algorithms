#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int cnt = 0;
        int majority = 0;
        for (int num: nums) {
            if (cnt == 0) {
                majority = num;
                cnt++;
            } else {
                if (majority == num) cnt++;
                else cnt--;
            }
        }
        if (cnt <= 0) return -1;
        cnt = 0;
        for (int num: nums) {
            if (num == majority) cnt++;
        }
        return cnt > nums.size() / 2 ? majority : -1;
    }
};