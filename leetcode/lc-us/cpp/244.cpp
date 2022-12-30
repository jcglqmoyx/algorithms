#include <bits/stdc++.h>

using namespace std;

class WordDistance {
    unordered_map<string, vector<int>> map;
public:
    WordDistance(vector<string> &words) {
        for (int i = 0; i < words.size(); i++) {
            map[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int> arr1 = map[word1];
        vector<int> arr2 = map[word2];
        int shortest_distance = INT32_MAX;
        int i = 0, j = 0;
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j]) {
                shortest_distance = min(shortest_distance, arr2[j] - arr1[i]);
                i++;
            } else {
                shortest_distance = min(shortest_distance, arr1[i] - arr2[j]);
                j++;
            }
        }
        return shortest_distance;
    }
};