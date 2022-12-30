#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int num = 0;
        char sign = '+';
        int n = (int) s.size();
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                num = num * 10 - '0' + s[i];
            }
            if (s[i] != ' ' && !isdigit(s[i]) || i == n - 1) {
                if (sign == '+') {
                    nums.push_back(num);
                } else if (sign == '-') {
                    nums.push_back(-num);
                } else if (sign == '*') {
                    int last = nums.back();
                    nums.pop_back();
                    nums.push_back(last * num);
                } else if (sign == '/') {
                    int last = nums.back();
                    nums.pop_back();
                    nums.push_back(last / num);
                }
                sign = s[i];
                num = 0;
            }
        }
        int res = 0;
        for (int number: nums) {
            res += number;
        }
        return res;
    }
};