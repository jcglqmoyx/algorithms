#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int first = 1, second = 1;
        vector<int> nums = {1, 1};
        for (int i = 3; nums.back() < k; i++) {
            int third = first + second;
            nums.push_back(third);
            first = second;
            second = third;
        }
        int count = 0;
        for (int i = (int) nums.size() - 1; i >= 0; i--) {
            while (k >= nums[i]) {
                k -= nums[i];
                count++;
            }
            if (!k) break;
        }
        return count;
    }
};