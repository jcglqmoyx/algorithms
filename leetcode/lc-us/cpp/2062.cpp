#include <bits/stdc++.h>

using namespace std;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = (int) word.size();
        if (n < 5) return 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> hash;
            int j = i;
            for (; j < n && is_vowel(word[j]); j++) {
                hash[word[j]]++;
                if (hash.size() == 5) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};