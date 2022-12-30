#include <bits/stdc++.h>

using namespace std;

class Solution {
    int update(const string &target, int i, const string &source) {
        int j = 0;
        while (i < target.size() && j < source.size()) {
            if (target[i] == source[j]) i++, j++;
            else j++;
        }
        return i;
    }

public:
    int shortestWay(string source, string target) {
        int i = 0;
        int res = 0;
        while (i < target.size()) {
            res++;
            int t = update(target, i, source);
            if (t == i) return -1;
            i = t;
        }
        return res;
    }
};