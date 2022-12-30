#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countValidWords(string sentence) {
        int cnt = 0;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            bool flag = true;
            for (char c: word) {
                if (!islower(c) && c != '-' && c != '!' && c != '.' && c != ',') {
                    flag = false;
                    break;
                }
            }
            int hyphen = 0, n = (int) word.size();
            for (int i = 0; i < n; i++) {
                if (word[i] == '-') {
                    hyphen++;
                    if (hyphen > 1) {
                        flag = false;
                        break;
                    }
                    if (i == 0 || i == n - 1) {
                        flag = false;
                        break;
                    }
                    if (!islower(word[i - 1]) || !islower(word[i + 1])) {
                        flag = false;
                        break;
                    }
                } else if (word[i] == '!' || word[i] == '.' || word[i] == ',') {
                    if (i != n - 1) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) cnt++;
        }
        return cnt;
    }
};