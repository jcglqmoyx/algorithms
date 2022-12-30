#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int> &nums, int k) {
        int n = (int) nums.size();
        int index = n - 1;
        int carry = 0;
        while (index >= 0 || k) {
            if (index >= 0 && k) {
                int sum = nums[index] + k % 10 + carry;
                nums[index--] = sum % 10;
                carry = sum / 10;
                k /= 10;
            } else if (index >= 0) {
                int sum = nums[index] + carry;
                nums[index--] = sum % 10;
                carry = sum / 10;
            } else {
                int sum = k % 10 + carry;
                carry = sum / 10;
                nums.insert(nums.begin(), sum % 10);
                k /= 10;
            }
        }
        if (carry) {
            nums.insert(nums.begin(), 1);
        }
        return nums;
    }
};