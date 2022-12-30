#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

const int N = 1505, P = 13331;
int n;
ULL h[N], p[N];
unordered_set<ULL> hash_values;

void init(string &s) {
    n = (int) s.length();
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * P + s[i - 1];
        p[i] = p[i - 1] * P;
    }
}

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

bool valid(string &s, int len) {
    hash_values.clear();
    for (int i = 1; i + len - 1 <= n; i++) {
        ULL hash_value = get(i, i + len - 1);
        if (hash_values.count(hash_value)) return true;
        hash_values.insert(hash_value);
    }
    return false;
}

class Solution {
public:
    int longestRepeatingSubstring(string s) {
        init(s);
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (valid(s, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};