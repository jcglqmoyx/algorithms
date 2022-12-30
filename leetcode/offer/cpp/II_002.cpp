#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = (int) a.size(), n = (int) b.size();
        int i = m - 1, j = n - 1;
        int carry = 0, sum;
        string res;
        while (~i || ~j) {
            if (~i && ~j) {
                sum = a[i] + b[j] + carry - '0' * 2;
                i--;
                j--;
            } else if (~i) {
                sum = a[i] + carry - '0';
                i--;
            } else if (~j) {
                sum = b[j] + carry - '0';
                j--;
            }
            string s = to_string(sum % 2);
            res += s;
            carry = sum >> 1;
        }
        if (carry) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};