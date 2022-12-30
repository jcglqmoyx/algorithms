#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int low = 0, high = (int) s.length() - 1;
        while (low < high) {
            while (low < high && !is_vowel(s[low])) {
                low++;
            }
            while (low < high && !is_vowel(s[high])) {
                high--;
            }
            swap(s[low], s[high]);
            low++;
            high--;
        }
        return s;
    }

    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};