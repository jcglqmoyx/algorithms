#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>> &edges) {
        unordered_map<int, int> degrees;
        for (const vector<int> &edge: edges) {
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
        int max_degree = 0;
        int center = -1;
        for (const auto x: degrees) {
            if (x.second > max_degree) {
                max_degree = x.second;
                center = x.first;
            }
        }
        return center;
    }
};