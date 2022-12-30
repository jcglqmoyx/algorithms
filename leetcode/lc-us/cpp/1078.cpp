#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> occurrences, words;
        int low = 0;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                words.push_back(text.substr(low, i - low));
                low = i + 1;
            }
            if (i == text.size() - 1) {
                words.push_back(text.substr(low));
            }
        }
        for (int i = 0; i < words.size() - 2; i++) {
            if (words[i] == first && words[i + 1] == second) {
                occurrences.push_back(words[i + 2]);
            }
        }
        return occurrences;
    }
};