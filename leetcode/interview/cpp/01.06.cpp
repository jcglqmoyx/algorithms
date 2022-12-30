#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string compressString(string S) {
        if (S.length() <= 2) return S;
        int count = 1;
        string compressed;
        for (int i = 1; i < S.length(); i++) {
            if (S[i] == S[i - 1]) count++;
            else {
                compressed += S[i - 1] + to_string(count);
                count = 1;
            }
            if (i == S.length() - 1) compressed += S[i] + to_string(count);
        }
        return compressed.length() < S.length() ? compressed : S;
    }
};