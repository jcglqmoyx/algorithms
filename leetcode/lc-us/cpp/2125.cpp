#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string> &bank) {
        int n = (int) bank.size(), res = 0;
        for (int i = 0, pre = 0; i < n; i++) {
            int cnt = 0;
            for (char c: bank[i]) {
                if (c & 1) {
                    cnt++;
                }
            }
            if (pre) res += cnt * pre;
            if (cnt) pre = cnt;
        }
        return res;
    }
};