#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        int cnt1[26] = {}, cnt2[26] = {};
        for (char c: word1) cnt1[c - 'a']++;
        for (char c: word2) cnt2[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (cnt1[i] && cnt2[j]) {
                    cnt1[i]--, cnt2[j]--;
                    cnt1[j]++, cnt2[i]++;
                    int a = 0, b = 0;
                    for (int freq: cnt1) {
                        if (freq) a++;
                    }
                    for (int freq: cnt2) {
                        if (freq) b++;
                    }
                    if (a == b) return true;
                    cnt1[i]++, cnt2[j]++;
                    cnt1[j]--, cnt2[i]--;
                }
            }
        }
        return false;
    }
};