#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        string res;
        for (int i = (int) num.size() - 1; i >= 0; i--) {
            if ((num[i] - '0') & 1) {
                res = num.substr(0, i + 1);
                break;
            }
        }
        return res;
    }
};