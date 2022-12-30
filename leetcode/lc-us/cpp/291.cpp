#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<char, string> char_word;
    unordered_map<string, char> word_char;

    bool backtrack(string &pattern, int pi, string &s, int si) {
        if (pi >= pattern.length()) return si >= s.length();
        if (si >= s.length()) return false;
        char c = pattern[pi];
        if (char_word.find(c) == char_word.end()) {
            for (int i = si; i < s.length(); i++) {
                string word = s.substr(si, i - si + 1);
                if (word_char.find(word) == word_char.end()) {
                    char_word[c] = word;
                    word_char[word] = c;
                    if (backtrack(pattern, pi + 1, s, i + 1)) {
                        return true;
                    }
                    char_word.erase(c);
                    word_char.erase(word);
                } else {
                    if (word_char[word] == c) {
                        if (backtrack(pattern, pi + 1, s, i + 1)) {
                            return true;
                        }
                    }
                }
            }
        } else {
            string word = char_word[c];
            if (si + word.size() <= s.size()) {
                string temp = s.substr(si, word.size());
                if (temp == word) {
                    if (backtrack(pattern, pi + 1, s, si + (int) word.size())) {
                        return true;
                    }
                }
            } else {
                return false;
            }
        }
        return false;
    }

public:
    bool wordPatternMatch(string pattern, string s) {
        return backtrack(pattern, 0, s, 0);
    }
};