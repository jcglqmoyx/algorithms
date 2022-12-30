#include <bits/stdc++.h>

using namespace std;

class Solution {
    using ULL = unsigned long long;
    const int P = 13331;
    vector<ULL> h, p;

    void init(string &s, int n) {
        h.resize(n + 1), p.resize(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++) {
            h[i] = h[i - 1] * P + s[i - 1];
            p[i] = p[i - 1] * P;
        }
    }

    ULL get(int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = (int) s.size();
        init(s, n);
        unordered_map<ULL, int> hash;
        unordered_map<char, int> letter_cnt;
        for (int i = 0; i < minSize; i++) letter_cnt[s[i]]++;
        if (letter_cnt.size() <= maxLetters) hash[get(1, minSize)]++;
        for (int i = 1, j = minSize + 1; j <= n; j++) {
            letter_cnt[s[j - 1]]++;
            letter_cnt[s[i - 1]]--;
            if (letter_cnt[s[i - 1]] == 0) letter_cnt.erase(s[i - 1]);
            i++;
            if (letter_cnt.size() <= maxLetters) hash[get(i, j)]++;
        }
        int res = 0;
        for (auto &[k, v]: hash) res = max(res, v);
        return res;
    }
};