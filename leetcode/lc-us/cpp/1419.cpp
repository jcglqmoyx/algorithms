#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = (int) croakOfFrogs.size();
        if (n % 5) return -1;
        int map[128] = {0};
        for (char c: croakOfFrogs) map[c]++;
        int count = map['c'];
        if (map['r'] != count || map['o'] != count || map['a'] != count || map['k'] != count) return -1;
        int c = 0, r = 0, o = 0, a = 0, k = 0;
        int res = 0;
        for (char ch: croakOfFrogs) {
            if (ch == 'c') {
                c++;
                res = max(res, c);
            } else if (ch == 'r') {
                r++;
                if (r > c) return -1;
            } else if (ch == 'o') {
                o++;
                if (o > r) return -1;
            } else if (ch == 'a') {
                a++;
                if (a > o) return -1;
            } else if (ch == 'k') {
                k++;
                if (k > a) return -1;
                c--;
                r--;
                o--;
                a--;
                k--;
            }
        }
        return res;
    }
};