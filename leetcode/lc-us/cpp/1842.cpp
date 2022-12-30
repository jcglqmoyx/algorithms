#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string nextPalindrome(string num) {
        int n = (int) num.size();
        if (n == 1) return "";
        int idx = -1;
        for (int i = n / 2 - 1; i; i--) {
            if (num[i] > num[i - 1]) {
                idx = i;
                char mn = num[i];
                int k = i;
                for (int j = i + 1; j < n / 2; j++) {
                    if (num[j] < mn && num[j] > num[i - 1]) {
                        mn = num[j];
                        k = j;
                    }
                }
                swap(num[i - 1], num[k]);
                break;
            }
        }
        if (idx == -1) return "";
        sort(num.begin() + idx, num.begin() + n / 2);
        for (int i = n - 1; i >= n >> 1; i--) {
            num[i] = num[n - 1 - i];
        }
        return num;
    }
};