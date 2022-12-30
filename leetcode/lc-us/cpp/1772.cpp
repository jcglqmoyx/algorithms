#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> sortFeatures(vector<string> &features, vector<string> &responses) {
        vector<string> res;
        unordered_map<string, int> frequency;
        unordered_map<string, int> feature_set;
        for (int i = 0; i < features.size(); i++) feature_set[features[i]] = i;
        for (string &response: responses) {
            stringstream ss(response);
            string feature;
            unordered_set<string> temp;
            while (ss >> feature) {
                temp.insert(feature);
            }
            for (auto &f: temp) {
                frequency[f]++;
            }
        }
        sort(features.begin(), features.end(), [&](string &f1, string &f2) {
            if (frequency[f1] != frequency[f2]) {
                return frequency[f1] > frequency[f2];
            } else {
                return feature_set[f1] < feature_set[f2];
            }
        });
        return features;
    }
};