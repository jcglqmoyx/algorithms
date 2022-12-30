#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findClosest(vector<string> &words, string word1, string word2) {
        int m = -1, n = -1;
        int dist = 100000;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                m = i;
                if (n != -1) {
                    dist = min(dist, i - n);
                }
            } else if (words[i] == word2) {
                n = i;
                if (m != -1) {
                    dist = min(dist, i - m);
                }
            }
        }
        return dist;
    }
};