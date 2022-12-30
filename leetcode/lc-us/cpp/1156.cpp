#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get(string text) {
        int res = 0, n = (int) text.size();
        int map[123];
        memset(map, -1, sizeof map);
        for (int i = n - 1; ~i; i--) {
            if (map[text[i]] == -1) {
                map[text[i]] = i;
            }
        }
        for (int i = 0; i < n; i++) {
            int first, second = 0, third = 0;
            int j = i + 1;
            while (j < n && text[j] == text[i]) j++;
            first = j - i;
            if (j < n - 1 && text[j + 1] == text[i]) {
                int k = j + 1;
                while (k < n && text[k] == text[i]) k++;
                second = k - j - 1;
                if (map[text[i]] >= k) {
                    third = 1;
                }
            } else {
                if (map[text[i]] > j) {
                    second = 1;
                }
            }
            i = j - 1;
            res = max(res, first + second + third);
        }
        return res;
    }

public:
    int maxRepOpt1(string text) {
        return max(get(text), get(string(text.rbegin(), text.rend())));
    }
};