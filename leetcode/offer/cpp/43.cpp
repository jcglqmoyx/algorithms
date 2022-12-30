#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        vector<int> nums;
        while (n) nums.push_back(n % 10), n /= 10;
        int high = (int) nums.size() - 1;
        int res = 0;
        for (int i = 0; i <= high; i++) {
            int left = 0, right = 0, t = 1;
            for (int j = i - 1; j >= 0; j--) right = right * 10 + nums[j], t *= 10;
            for (int j = high; j > i; j--) left = left * 10 + nums[j];
            res += left * t;
            if (nums[i] == 1) res += right + 1;
            else if (nums[i] > 1) res += t;
        }
        return res;
    }
};