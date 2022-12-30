#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSwapValues(vector<int> &array1, vector<int> &array2) {
        int s1 = 0, s2 = 0;
        unordered_set<int> set;
        for (int e: array1) s1 += e;
        for (int e: array2) {
            s2 += e;
            set.insert(e);
        }
        int diff = s2 - s1;
        for (int a: array1) {
            int b = diff / 2 + a;
            if (set.find(b) != set.end() && s1 + b - a == s2 - b + a) {
                return {a, b};
            }
        }
        return {};
    }
};