#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2) {
        vector<int> res;
        int carry = 0;
        int n = (int) arr1.size(), m = (int) arr2.size();
        for (int i = n - 1, j = m - 1; ~i || ~j;) {
            if (~i && ~j) {
                int sum = arr1[i] + arr2[j] - carry;
                res.push_back(sum & 1);
                carry = sum >> 1;
                i--, j--;
            } else if (~i) {
                int sum = arr1[i] - carry;
                res.push_back(sum & 1);
                carry = sum >> 1;
                i--;
            } else {
                int sum = arr2[j] - carry;
                res.push_back(sum & 1);
                carry = sum >> 1;
                j--;
            }
        }
        if (carry) {
            res.push_back(1);
            res.push_back(1);
        }
        while (res.size() > 1 && res.back() == 0) res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};