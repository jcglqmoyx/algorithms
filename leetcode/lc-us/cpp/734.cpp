#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string> &sentence1, vector<string> &sentence2, vector<vector<string>> &similarPairs) {
        int n1 = (int) sentence1.size(), n2 = (int) sentence2.size();
        if (n1 != n2) return false;
        unordered_map<string, unordered_set<string>> map;
        for (const vector<string> &similar_pair: similarPairs) {
            map[similar_pair[0]].insert(similar_pair[0]);
            map[similar_pair[1]].insert(similar_pair[0]);
        }
        for (int i = 0; i < n1; i++) {
            string word1 = sentence1[i], word2 = sentence2[i];
            if (word1 != word2 && !map[word1].count(word2) && !map[word2].count(word1)) {
                return false;
            }
        }
        return true;
    }
};