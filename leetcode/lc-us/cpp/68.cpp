#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        int n = (int) words.size();
        for (int i = 0; i < n; i++) {
            int j = i + 1, sum = (int) words[i].size();
            while (j < n && sum + 1 + words[j].size() <= maxWidth) sum += (int) words[j].size() + 1, j++;
            if (j == i + 1) {
                string s = words[i];
                for (int k = 0; k < maxWidth - words[i].size(); k++) {
                    s.push_back(' ');
                }
                res.push_back(s);
                continue;
            }
            int word_length = 0;
            for (int k = i; k < j; k++) word_length += (int) words[k].size();
            int spaces = maxWidth - word_length;
            int dist = spaces / (j - i - 1), mod = spaces - spaces / (j - i - 1) * (j - i - 1);
            string s;
            if (j == n) {
                for (int k = i; k < j; k++) {
                    s += words[k];
                    s.push_back(' ');
                }
                for (int k = maxWidth - (int) s.size(); k > 0; k--) s.push_back(' ');
                if (s.size() > maxWidth) {
                    s.pop_back();
                }
                res.push_back(s);
                break;
            }
            for (int k = i; k < j; k++) {
                s += words[k];
                if (k == j - 1) break;
                for (int p = 0; p < dist; p++) {
                    s.push_back(' ');
                }
                if (mod == 0) continue;
                s.push_back(' ');
                mod--;
            }
            i = j - 1;
            res.push_back(s);
        }
        return res;
    }
};