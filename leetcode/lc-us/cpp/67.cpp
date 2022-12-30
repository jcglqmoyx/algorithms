#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = (int) a.size() - 1, j = (int) b.size() - 1;
        int carry = 0, sum;
        while (i >= 0 && j >= 0) {
            sum = a[i] - '0' + b[j] - '0' + carry;
            carry = sum / 2;
            res += to_string(sum % 2);
            i--, j--;
        }
        while (i >= 0) {
            sum = a[i] - '0' + carry;
            carry = sum / 2;
            res += to_string(sum % 2);
            i--;
        }
        while (j >= 0) {
            sum = b[j] - '0' + carry;
            carry = sum / 2;
            res += to_string(sum % 2);
            j--;
        }
        if (carry) {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};