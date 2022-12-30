#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string> &arr, int k) {
        unordered_map<string, int> cnt;
        for (string &s: arr) cnt[s]++;
        int i = 0;
        for (string &s: arr) {
            if (cnt[s] == 1) i++;
            if (i == k) return s;
        }
        return "";
    }
};