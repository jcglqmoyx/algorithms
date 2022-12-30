#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int edgeScore(vector<int> &edges) {
        int n = (int) edges.size();
        vector<long long> score(n);
        for (int i = 0; i < n; i++) {
            score[edges[i]] += i;
        }
        int res = 0;
        long long max_score = 0;
        for (int i = 0; i < n; i++) {
            if (score[i] > max_score) {
                max_score = score[i];
                res = i;
            }
        }
        return res;
    }
};