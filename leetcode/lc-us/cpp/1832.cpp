#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int cnt[26] = {};
        for (char c: sentence) cnt[c - 'a']++;
        return all_of(cnt, cnt + 26, [](int x) {
            return x;
        });
    }
};