#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string> &words) {
        vector<vector<int>> index_pairs;
        for (string &w: words) {
            int n = (int) w.size();
            vector<int> ne(n, -1);
            for (int i = 1, j = -1; i < n; i++) {
                while (j >= 0 && w[i] != w[j + 1]) j = ne[j];
                if (w[i] == w[j + 1]) j++;
                ne[i] = j;
            }
            for (int i = 0, j = -1; i < text.length(); i++) {
                while (j != -1 && text[i] != w[j + 1]) j = ne[j];
                if (text[i] == w[j + 1]) j++;
                if (j == n - 1) {
                    index_pairs.push_back({i - j, i});
                    j = ne[j];
                }
            }
        }
        sort(index_pairs.begin(), index_pairs.end());
        return index_pairs;
    }
};