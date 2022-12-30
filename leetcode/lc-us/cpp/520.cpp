#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for (char c: word) {
            if (isupper(c)) {
                count++;
            }
        }
        return !count || count == (int) word.size() || count == 1 && isupper(word[0]);
    }
};