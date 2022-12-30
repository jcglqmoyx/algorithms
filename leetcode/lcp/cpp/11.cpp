#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int expectNumber(vector<int> &scores) {
        unordered_set<int> set;
        for (int score: scores) {
            set.insert(score);
        }
        return set.size();
    }
};