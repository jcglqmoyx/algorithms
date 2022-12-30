#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumBuckets(string s) {
        const char BUCKET = 'B', HOUSE = 'H', PROCESSED = 'P';
        int n = (int) s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == HOUSE) {
                if (i < n - 1 && s[i + 1] == '.') {
                    s[i + 1] = BUCKET;
                    cnt++;
                    s[i] = PROCESSED;
                } else if (i && s[i - 1] == '.') {
                    s[i - 1] = BUCKET;
                    cnt++;
                    s[i] = PROCESSED;
                } else {
                    return -1;
                }
            } else if (s[i] == BUCKET) {
                if (i < n - 1 && s[i + 1] == HOUSE) s[i + 1] = PROCESSED;
            }
        }
        return cnt;
    }
};