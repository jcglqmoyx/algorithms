#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = (int) seq.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                res[i] = i & 1;
            } else {
                res[i] = (i + 1) & 1;
            }
        }
        return res;
    }
};