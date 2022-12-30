#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfDigits(vector<int> &nums) {
        int min_value = 100;
        for (int num: nums) {
            min_value = min(min_value, num);
        }
        int sum = 0;
        while (min_value) {
            sum += min_value % 10;
            min_value /= 10;
        }
        return sum % 2 == 1 ? 0 : 1;
    }
};