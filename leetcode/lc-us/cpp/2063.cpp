#include <bits/stdc++.h>

using namespace std;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

class Solution {
public:
    long long countVowels(string word) {
        using LL = long long;
        LL res = 0, n = (LL) word.size();
        for (LL i = 0; i < n; i++) {
            if (is_vowel(word[i])) res += (i + 1) * (n - i);
        }
        return res;
    }
};