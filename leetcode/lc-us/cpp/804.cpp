#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        unordered_set<string> translations;
        string morse_codes[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                                  "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                                  "-.--", "--.."};
        for (const string &word: words) {
            string morse_code;
            for (char c: word) {
                morse_code += morse_codes[c - 'a'];
            }
            translations.insert(morse_code);
        }
        return (int) translations.size();
    }
};