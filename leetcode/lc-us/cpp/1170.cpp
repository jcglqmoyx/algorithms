#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
        vector<int> res(queries.size());
        int count[12] = {};
        for (const string &word: words) {
            count[freq(word)]++;
        }
        for (int i = 9; i >= 1; i--) {
            count[i] += count[i + 1];
        }
        for (int i = 0; i < res.size(); i++) {
            int frequency = freq(queries[i]);
            res[i] = count[frequency + 1];
        }
        return res;
    }

    static int freq(const string &word) {
        int count[26] = {0};
        for (char c: word) {
            count[c - 'a']++;
        }
        for (int i: count) {
            if (i) {
                return i;
            }
        }
        return 1;
    }
};