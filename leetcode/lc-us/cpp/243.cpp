#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string> &words, string word1, string word2) {
        int index1 = -1, index2 = -1;
        int shortest_distance = INT32_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                index1 = i;
                if (index2 != -1) {
                    shortest_distance = min(shortest_distance, i - index2);
                }
            } else if (words[i] == word2) {
                index2 = i;
                if (index1 != -1) {
                    shortest_distance = min(shortest_distance, i - index1);
                }
            }
        }
        return shortest_distance;
    }
};