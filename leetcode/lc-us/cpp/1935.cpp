#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        vector<string> words;
        string word;
        while (ss >> word) words.push_back(word);
        int cnt = 0;
        for (string &w: words) {
            bool flag = true;
            for (char c: w) {
                for (char ch: brokenLetters) {
                    if (c == ch) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (flag) cnt++;
        }
        return cnt;
    }
};