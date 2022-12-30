#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string res;
        int n = (int) num.size();
        int cnt = 0;
        char prev;
        for (int i = 0; i < n; i++) {
            char c = num[i];
            if (cnt == 0 || c == prev) cnt++;
            else cnt = 1;
            if (cnt >= 3) {
                res = max(res, num.substr(i - 2, 3));
            }
            prev = c;
        }
        return res;
    }
};