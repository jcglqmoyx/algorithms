#include <bits/stdc++.h>

using namespace std;

class Solution {
    int calc(string &s, char c, int k) {
        int res = 0, cnt = 0, n = (int) s.size();
        for (int l = 0, r = 0; r < n; r++) {
            if (s[r] != c) cnt++;
            while (cnt > k) {
                if (s[l] != c) cnt--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(calc(answerKey, 'T', k), calc(answerKey, 'F', k));
    }
};