#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;

    bool backtrack(string &num, int start, string &prev, string &sum, int count) {
        if (start == n) {
            return count >= 3;
        }
        string value;
        for (int i = start; i < n; i++) {
            if (i > start && num[start] == '0') break;
            value.push_back(num[i]);
            if (count >= 2) {
                if (value > sum) break;
                else if (value < sum) continue;
            }
            sum = plus(prev, value);
            if (backtrack(num, i + 1, value, sum, count + 1)) return true;
        }
        return false;
    }

    string plus(string &a, string &b) {
        string res;
        int i = (int) a.length() - 1, j = (int) b.length() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int x = i >= 0 ? a[i--] - '0' : 0;
            int y = j >= 0 ? b[j--] - '0' : 0;
            int sum = x + y + carry;
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

public:
    bool isAdditiveNumber(string num) {
        n = (int) num.size();
        if (n < 3) return false;
        string prev = "0", sum = "0";
        return backtrack(num, 0, prev, sum, 0);
    }
};