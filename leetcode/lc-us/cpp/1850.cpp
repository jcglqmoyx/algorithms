#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMinSwaps(string num, int k) {
        string s = num;
        int n = num.length();
        while (k--) {
            for (int i = n - 1; i >= 1; i--) {
                if (num[i] > num[i - 1]) {
                    char c = num[i - 1];
                    int index = i;
                    for (int j = i; j < n; j++) {
                        if (num[j] > c) {
                            if (num[index] > num[j]) {
                                index = j;
                            }
                        }
                    }
                    swap(num[i - 1], num[index]);
                    sort(num.begin() + i, num.end());
                    break;
                }
            }
        }
        int l, r;
        for (int i = 0; i < n; i++) {
            if (s[i] != num[i]) {
                l = i;
                break;
            }
        }
        for (int i = n - 1;; i--) {
            if (s[i] != num[i]) {
                r = i;
                break;
            }
        }
        int cnt = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] != num[i]) {
                int j = i + 1;
                while (s[j] != num[i]) j++;
                while (s[i] != num[i]) {
                    swap(s[j], s[j - 1]);
                    j--;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};