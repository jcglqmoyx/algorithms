#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        vector<string> res(k);
        unordered_map<string, int> freq;
        for (string &word: words) {
            freq[word]++;
        }
        vector<pair<string, int>> count(freq.begin(), freq.end());
        sort(count.begin(), count.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
            if (a.second == b.second) return a.first < b.first;
            else return a.second > b.second;
        });
        for (int i = 0; i < k; i++) {
            res[i] = count[i].first;
        }
        return res;
    }
};