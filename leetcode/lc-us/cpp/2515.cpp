#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int closetTarget(vector<string> &words, string target, int startIndex) {
        int n = (int) words.size(), res = n;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                res = min(res, min(abs(startIndex - i), n - abs(startIndex - i)));
            }
        }
        return res == n ? -1 : res;
    }
};