#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        long first = INT64_MIN, second = INT64_MIN, third = INT64_MIN;
        for (int num: nums) {
            if (num > third) {
                if (num > second) {
                    if (num > first) {
                        third = second;
                        second = first;
                        first = num;
                    } else {
                        if (num != first) {
                            third = second;
                            second = num;
                        }
                    }
                } else {
                    if (num != second) {
                        third = num;
                    }
                }
            }
        }
        return third == INT64_MIN ? (int) first : (int) third;
    }
};