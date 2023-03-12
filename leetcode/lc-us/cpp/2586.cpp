#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    int vowelStrings(vector<string> &words, int left, int right) {
        int res = 0;
        for (int i = left; i <= right; i++) {
            if (is_vowel(words[i].front()) && is_vowel(words[i].back())) {
                res++;
            }
        }
        return res;
    }
};