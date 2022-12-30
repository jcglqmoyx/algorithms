#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = (int) s.size();
        if (n < k) return 0;
        unordered_map<char, int> map;
        for (int i = 0; i < k; i++) map[s[i]]++;
        int count = 0;
        if (map.size() == k) count++;
        for (int i = k; i < n; i++) {
            map[s[i]]++;
            map[s[i - k]]--;
            if (map[s[i - k]] == 0) map.erase(s[i - k]);
            if (map.size() == k) count++;
        }
        return count;
    }
};