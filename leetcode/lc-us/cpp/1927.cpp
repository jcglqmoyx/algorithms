#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = (int) num.size();
        int sum = 0, cnt = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') cnt++;
            else sum += num[i] - '0';
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') cnt--;
            else sum -= num[i] - '0';
        }
        if ((!sum && !cnt) || (cnt % 2 == 0 && sum * cnt < 0 && abs(cnt) / 2 * 9 == abs(sum))) return false;
        return true;
    }
};