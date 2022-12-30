#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
        string sentence1, sentence2;
        for (const string &word: word1) {
            sentence1 += word;
        }
        for (const string &word: word2) {
            sentence2 += word;
        }
        return sentence1 == sentence2;
    }
};