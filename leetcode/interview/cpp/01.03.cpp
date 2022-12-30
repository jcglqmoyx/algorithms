#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string replaceSpaces(string S, int length) {
        int i = length - 1, j = (int) S.length() - 1;
        while (i >= 0) {
            if (S[i] == ' ') {
                S[j--] = '0';
                S[j--] = '2';
                S[j--] = '%';
            } else {
                S[j--] = S[i];
            }
            i--;
        }
        return S.substr(j + 1);
    }
};