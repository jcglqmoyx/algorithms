#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        string res;
        vector<string> words;
        int low = 0, count_space = 0;
        for (int i = 0; i < text.length(); i++) {
            while (low < text.length() && text[low] == ' ') {
                low++;
                count_space++;
            }
            while (i < low) {
                i++;
            }
            if (i < text.length() && text[i] == ' ') {
                words.push_back(text.substr(low, i - low));
                low = i;
            } else if (i == text.length() - 1) {
                words.push_back(text.substr(low));
            }
        }
        while (low < text.length() && text[low] == ' ') {
            count_space++;
            low++;
        }
        if (words.size() == 1) {
            res += words[0];
            for (int i = 0; i < count_space; i++) {
                res += ' ';
            }
            return res;
        }
        int interval = count_space / ((int) words.size() - 1);
        for (int i = 0; i < words.size() - 1; i++) {
            res += words[i];
            for (int j = 0; j < interval; j++) {
                res += ' ';
            }
        }
        res += words.back();
        for (int i = 0; i < count_space % ((int) words.size() - 1); i++) {
            res += ' ';
        }
        return res;
    }
};