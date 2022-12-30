#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' ||
               c == 'O' || c == 'U';
    }

public:
    bool halvesAreAlike(string s) {
        int count = 0;
        for (int i = 0; i < s.length() / 2; i++) {
            if (is_vowel(s[i])) count++;
        }
        for (int i = (int) s.length() / 2; i < s.length(); i++) {
            if (is_vowel(s[i])) count--;
        }
        return count == 0;
    }
};