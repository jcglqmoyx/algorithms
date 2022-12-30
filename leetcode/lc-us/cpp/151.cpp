#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        ss << s;
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        word.clear();
        for (int i = (int) words.size() - 1; i >= 0; i--) {
            word += words[i] + " ";
        }
        word.pop_back();
        return word;
    }
};