#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int num = 0;
        char sign = '+';
        vector<int> nums;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                num = num * 10 - '0' + s[i];
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
                switch (sign) {
                    case '+':
                        nums.push_back(num);
                        break;
                    case '-':
                        nums.push_back(-num);
                        break;
                    case '*': {
                        int last = nums.back();
                        nums.pop_back();
                        nums.push_back(last * num);
                    }
                        break;
                    case '/': {
                        int last = nums.back();
                        nums.pop_back();
                        nums.push_back(last / num);
                    }
                        break;
                    default:
                        break;
                }
                sign = s[i];
                num = 0;
            }
        }
        int res = 0;
        for (int number: nums) res += number;
        return res;
    }
};