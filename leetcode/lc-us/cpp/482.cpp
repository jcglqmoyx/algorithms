#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        int count = 0;
        for (int i = (int) S.length() - 1; i >= 0; i--) {
            if (isalpha(S[i])) {
                res += toupper(S[i]);
                count++;
            } else if (isdigit(S[i])) {
                res += S[i];
                count++;
            }
            if (!res.empty() && count % K == 0 && res.back() != '-') {
                res += '-';
            }
        }
        if (res.back() == '-') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};