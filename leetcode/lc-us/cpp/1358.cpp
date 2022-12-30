#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = (int) s.size(), res = 0;
        unordered_map<char, int> hash;
        for (int i = 0, j = 0; j < n; j++) {
            hash[s[j]]++;
            if (hash.size() == 3) {
                while (hash[s[i]] > 1) hash[s[i]]--, i++;
                res += i + 1;
            }
        }
        return res;
    }
};