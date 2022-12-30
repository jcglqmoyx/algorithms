#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int num = left; num <= right; num++) {
            if (self_divisible(num)) {
                res.push_back(num);
            }
        }
        return res;
    }

private:
    bool self_divisible(int num) {
        int cp = num;
        while (num != 0) {
            int digit = num % 10;
            if (digit == 0) {
                return false;
            }
            if (cp % digit != 0) {
                return false;
            }
            num /= 10;
        }
        return true;
    }
};