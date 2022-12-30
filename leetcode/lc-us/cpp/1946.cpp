#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maximumNumber(string num, vector<int> &change) {
        bool flag = false;
        for (char &c: num) {
            int digit = c - '0';
            if (change[digit] >= digit) {
                c = (char) (change[digit] + '0');
                if (change[digit] > digit) flag = true;
            } else if (flag) break;
        }
        return num;
    }
};