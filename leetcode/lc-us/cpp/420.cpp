#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strongPasswordChecker(string password) {
        bool st[3] = {};
        for (char c: password) {
            if (isdigit(c)) st[0] = true;
            else if (islower(c)) st[1] = true;
            else if (isupper(c)) st[2] = true;
        }
        int type_count = 0;
        for (bool exists: st) {
            if (exists) type_count++;
        }
        int n = (int) password.size();
        if (n < 6) {
            return max(3 - type_count, 6 - n);
        } else {
            int d[3] = {0}, change = 0, del = n - 20, res = del;
            for (int i = 0; i < n; i++) {
                int j = i + 1;
                while (j < n && password[j] == password[i]) j++;
                int len = j - i;
                if (len >= 3) d[len % 3]++, change += len / 3;
                i = j - 1;
            }
            if (n <= 20) return max(3 - type_count, change);
            if (d[0] && del) {
                int t = min(d[0], del);
                change -= t, del -= t;
            }
            if (d[1] && del) {
                int t = min(d[1] << 1, del);
                change -= t >> 1, del -= t;
            }
            if (change && del) {
                int t = min(change * 3, del);
                change -= t / 3;
            }
            return res + max(3 - type_count, change);
        }
    }
};