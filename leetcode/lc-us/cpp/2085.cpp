#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countWords(vector<string> &words1, vector<string> &words2) {
        unordered_map<string, int> hash1, hash2;
        for (auto &w: words1) hash1[w]++;
        for (auto &w: words2) hash2[w]++;
        int cnt = 0;
        for (auto[k, v]: hash1) {
            if (v == 1 && hash2[k] == 1) cnt++;
        }
        return cnt;
    }
};