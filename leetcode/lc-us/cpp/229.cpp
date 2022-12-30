#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int n = (int) nums.size();
        int cand1 = 0, cand2 = 0;
        int count1 = 0, count2 = 0;
        for (int num: nums) {
            if (num == cand1) {
                count1++;
            } else if (num == cand2) {
                count2++;
            } else if (count1 == 0) {
                cand1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                cand2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        vector<int> majority_element;
        for (int num: nums) {
            if (num == cand1) {
                count1++;
            } else if (num == cand2) {
                count2++;
            }
        }
        if (count1 > n / 3) majority_element.push_back(cand1);
        if (count2 > n / 3) majority_element.push_back(cand2);
        return majority_element;
    }
};