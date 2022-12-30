#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> indices;
        int m = (int) s.size(), n = (int) p.size();
        if (m < n) return indices;
        int count[26] = {0};
        int temp[26] = {0};
        for (int i = 0; i < n; i++) {
            count[p[i] - 'a']++;
            temp[s[i] - 'a']++;
        }
        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (count[i] != temp[i]) {
                flag = false;
                break;
            }
        }
        if (flag) indices.push_back(0);
        for (int i = 1; i <= m - n; i++) {
            temp[s[i - 1] - 'a']--;
            temp[s[i + n - 1] - 'a']++;
            flag = true;
            for (int j = 0; j < 26; j++) {
                if (count[j] != temp[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) indices.push_back(i);
        }
        return indices;
    }
};