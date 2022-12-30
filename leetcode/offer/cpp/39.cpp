#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int cnt = 0;
        int majority_element = 0;
        for (int num: nums) {
            if (num == majority_element) cnt++;
            else {
                cnt--;
                if (cnt <= 0) {
                    majority_element = num;
                    cnt = 1;
                }
            }
        }
        return majority_element;
    }
};