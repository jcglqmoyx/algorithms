#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        string sentence;
        for (int i = 0; i < k; i++) {
            sentence += words[i] + ' ';
        }
        sentence.pop_back();
        return sentence;
    }
};