#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int count = 0;
        int l[26] = {0}, r[26] = {0};
        l[s[0] - 'a']++;
        for (int i = 1; i < n; i++) {
            r[s[i] - 'a']++;
        }
        if (valid(l, r)) count++;
        for (int i = 1; i < n - 1; i++) {
            l[s[i] - 'a']++;
            r[s[i] - 'a']--;
            if (valid(l, r)) count++;
        }
        return count;
    }

private:
    static bool valid(const int *l, const int *r) {
        int count1 = 0, count2 = 0;
        for (int i = 0; i < 26; i++) {
            if (l[i]) count1++;
            if (r[i]) count2++;
        }
        return count1 == count2;
    }
};