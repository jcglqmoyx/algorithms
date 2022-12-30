#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string> &words, string chars) {
        int res = 0;
        int count[26] = {};
        for (char c: chars) {
            count[c - 'a']++;
        }
        for (const string &word: words) {
            int cnt[26] = {0};
            for (char c: word) {
                cnt[c - 'a']++;
            }
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (count[i] < cnt[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res += (int) word.size();
            }
        }
        return res;
    }
};