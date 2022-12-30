#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int first = 0, second = 1, cur = 1;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) cur = 1;
            else if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '5') cur = first + second;
            else cur = second;
            first = second;
            second = cur;
        }
        return cur;
    }
};