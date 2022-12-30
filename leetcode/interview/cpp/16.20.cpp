#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string> &words) {
        vector<string> valid_words;
        int map[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
        for (string &word: words) {
            string num_str;
            int index = 0;
            bool flag = true;
            for (char c: word) {
                if (num[index++] - '0' != map[c - 'a']) {
                    flag = false;
                    break;
                }
            }
            if (flag) valid_words.push_back(word);
        }
        return valid_words;
    }
};