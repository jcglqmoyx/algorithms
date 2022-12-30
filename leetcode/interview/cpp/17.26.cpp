#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> computeSimilarities(vector<vector<int>> &docs) {
        unordered_map<int, vector<int>> mp1;
        for (int i = 0; i < docs.size(); ++i) {
            for (auto &word: docs[i]) {
                mp1[word].push_back(i);
            }
        }
        unordered_map<int, unordered_map<int, int>> mp2;
        for (auto &item: mp1) {
            auto &ids = item.second;
            for (int i = 0; i + 1 < ids.size(); ++i) {
                for (int j = i + 1; j < ids.size(); ++j) {
                    mp2[ids[i]][ids[j]]++;
                }
            }
        }

        vector<string> result;
        char temp[256];
        for (auto &item: mp2) {
            int id1 = item.first;
            for (auto &item2: item.second) {
                int id2 = item2.first;
                double similary = (double) item2.second / (int) (docs[id1].size() + docs[id2].size() - item2.second);
                sprintf(temp, "%d,%d: %0.4lf", id1, id2, similary + 1e-9);
                result.emplace_back(temp);
            }
        }
        return result;
    }
};