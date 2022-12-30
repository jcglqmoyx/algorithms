#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int step = 0;
        while (s != "1") {
            if (s.back() == '0') {
                s.pop_back();
            } else {
                int carry = 1, n = s.size();
                s.back() = '0';
                for (int i = n - 2; i >= 0; i--) {
                    int sum = s[i] - '0' + carry;
                    s[i] = sum % 2 + '0';
                    carry = sum / 2;
                    if (sum == 1) break;

                }
                if (carry) s = "1" + s;
            }
            step++;
        }
        return step;
    }
};