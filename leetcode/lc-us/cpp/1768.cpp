#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = (int) word1.size(), m = (int) word2.size();
        int i = 0, j = 0;
        string res;
        while (i < n || j < m) {
            if (i < n && j < m) {
                res.push_back(word1[i++]);
                res.push_back(word2[j++]);
            } else if (i < n) {
                res.push_back(word1[i++]);
            } else {
                res.push_back(word2[j++]);
            }
        }
        return res;
    }
};