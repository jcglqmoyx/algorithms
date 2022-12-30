#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        int map[123] = {};
        for (int i = 0; i < s1.length(); i++) {
            map[s1[i]]++;
            map[s2[i]]--;
        }
        return all_of(map, map + 123, [](int x) {
            return !x;
        });
    }
};