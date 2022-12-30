#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int low = 0, high = (int) numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                return {low, high};
            } else if (sum > target) {
                high--;
            } else {
                low++;
            }
        }
        return {};
    }
};