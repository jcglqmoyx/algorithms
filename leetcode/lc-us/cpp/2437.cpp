#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTime(string time) {
        int cnt = 0;
        for (int h = 0; h <= 23; h++) {
            for (int m = 0; m <= 59; m++) {
                string hs = to_string(h), ms = to_string(m);
                if (h < 10) hs = "0" + move(hs);
                if (m < 10) ms = "0" + move(ms);
                string s = move(hs) + ":" + move(ms);
                bool flag = true;
                for (int i = 0; i < 5; i++) {
                    if (s[i] != time[i] && time[i] != '?') {
                        flag = false;
                        break;
                    }
                }
                if (flag) cnt++;
            }
        }
        return cnt;
    }
};