#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i = 0, j = 0, n = (int) word1.size(), m = (int) word2.size();
        string merge;
        while (i < n || j < m) {
            if (i < n && j < m) {
                if (word1[i] > word2[j]) {
                    merge.push_back(word1[i++]);
                } else if (word1[i] < word2[j]) {
                    merge.push_back(word2[j++]);
                } else {
                    string sub1 = word1.substr(i);
                    string sub2 = word2.substr(j);
                    if (sub1 > sub2) merge.push_back(word1[i++]);
                    else merge.push_back(word2[j++]);
                }
            } else if (i < n) {
                merge += word1.substr(i);
                break;
            } else {
                merge += word2.substr(j);
                break;
            }
        }
        return merge;
    }
};