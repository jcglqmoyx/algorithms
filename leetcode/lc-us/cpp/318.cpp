#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string> &words) {
        if (words.empty()) return 0;
        int max_product = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            int len1 = (int) words[i].size();
            for (int j = i + 1; j < words.size(); j++) {
                int len2 = (int) words[j].size();
                if (len1 * len2 > max_product && valid(words[i], words[j])) max_product = len1 * len2;
            }
        }
        return max_product;
    }

    bool valid(string &word1, string &word2) {
        int mask1 = 0, mask2 = 0;
        for (char c: word1) {
            mask1 |= 1 << (c - 'a');
        }
        for (char c: word2) {
            mask2 |= 1 << (c - 'a');
        }
        return (mask1 & mask2) == 0;
    }
};