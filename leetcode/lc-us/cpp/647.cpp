#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = (int) s.size();
        int cnt = n;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int l = i, r = j;
                bool flag = true;
                while (l < r) {
                    if (s[l] != s[r]) {
                        flag = false;
                        break;
                    }
                    l++, r--;
                }
                if (flag) cnt++;
            }
        }
        return cnt;
    }
};