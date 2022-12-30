#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        for (char &c: paragraph) {
            if (isupper(c)) {
                c = tolower(c);
            }
        }
        unordered_set<string> set;
        for (const string &word: banned) {
            set.insert(word);
        }
        unordered_map<string, int> map;
        int low = 0;
        for (int i = 0; i < paragraph.length(); i++) {
            while (low < paragraph.length() && !isalpha(paragraph[low])) {
                low++;
            }
            if (!isalpha(paragraph[i])) {
                string word = paragraph.substr(low, i - low);
                if (!set.count(word)) {
                    map[word]++;
                }
                low = i + 1;
            }
            if (i == (int) paragraph.length() - 1) {
                string word = paragraph.substr(low);
                if (!word.empty() && !set.count(word)) {
                    map[word]++;
                }
            }
        }
        int max_freq = 0;
        string most_common_word;
        for (const auto &x: map) {
            if (x.second > max_freq) {
                max_freq = x.second;
                most_common_word = x.first;
            }
        }
        return most_common_word;
    }
};