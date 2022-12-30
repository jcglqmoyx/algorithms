#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestMultipleOfThree(vector<int> &digits) {
        string res;
        int n = (int) digits.size();
        int sum = 0;
        for (int d: digits) {
            sum += d;
            res.push_back(char(d + '0'));
        }
        sort(res.begin(), res.end(), greater<>());
        if (sum % 3 == 1) {
            bool flag = true;
            for (int i = n - 1; i >= 0; i--) {
                int x = res[i] - '0';
                if (x % 3 == 1) {
                    res = res.substr(0, i) + res.substr(i + 1);
                    flag = false;
                    break;
                }
            }
            if (flag) {
                int cnt = 0;
                for (int i = n - 1; i >= 0; i--) {
                    int x = res[i] - '0';
                    if (x % 3 == 2) {
                        res = res.substr(0, i) + res.substr(i + 1);
                        cnt++;
                        if (cnt == 2) break;
                    }
                }
            }
        } else if (sum % 3 == 2) {
            bool flag = true;
            for (int i = n - 1; i >= 0; i--) {
                int x = res[i] - '0';
                if (x % 3 == 2) {
                    res = res.substr(0, i) + res.substr(i + 1);
                    flag = false;
                    break;
                }
            }
            if (flag) {
                int cnt = 0;
                for (int i = n - 1; i >= 0; i--) {
                    int x = res[i] - '0';
                    if (x % 3 == 1) {
                        res = res.substr(0, i) + res.substr(i + 1);
                        cnt++;
                        if (cnt == 2) break;
                    }
                }
            }
        }
        if (res.front() == '0') res = "0";
        return res;
    }
};