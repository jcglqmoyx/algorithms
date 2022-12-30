#include <bits/stdc++.h>

using namespace std;

class WordsFrequency {
    unordered_map<string, int> map;
public:
    WordsFrequency(vector<string> &book) {
        for (string &word: book) {
            map[word]++;
        }
    }

    int get(string word) {
        return map[word];
    }
};