#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string> &words, string word1, string word2) {
        unordered_map<string, int> map;
        int res = (int) words.size();
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1 && map.count(word2)) {
                res = min(res, i - map[word2]);
            } else if (words[i] == word2 && map.count(word1)) {
                res = min(res, i - map[word1]);
            }
            map[words[i]] = i;
        }
        return res;
    }
};
