#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minimizeResult(string s) {
        auto eval = [](string t) {
            if (t[0] == '(') t = "1" + t;
            if (t.back() == ')') t.push_back('1');
            vector<int> nums;
            int num = 0;
            for (char c: t) {
                if (isdigit(c)) num = num * 10 + c - '0';
                else nums.push_back(num), num = 0;
            }
            nums.push_back(num);
            return nums[0] * (nums[1] + nums[2]) * nums[3];
        };

        string res;
        int n = (int) s.size();
        int idx = (int) s.find('+');
        int mn = INT32_MAX;
        for (int i = 0; i < idx; i++) {
            for (int j = idx + 1; j < n; j++) {
                string t = s.substr(0, i);
                t += '(';
                t += s.substr(i, j - i + 1);
                t += ')';
                t += s.substr(j + 1);
                int val = eval(t);
                if (val < mn) {
                    mn = val;
                    res = t;
                }
            }
        }
        return res;
    }
};