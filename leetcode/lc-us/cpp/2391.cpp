#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel) {
        int n = (int) garbage.size();
        string s = "MPG";
        vector<int> right(3);
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += (int) garbage[i].size();
            for (int j = 0; j < 3; j++) {
                if (garbage[i].find(s[j]) != string::npos) {
                    right[j] = i;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < right[i]; j++) {
                res += travel[j];
            }
        }
        return res;
    }
};