#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int> &arr) {
        int n = (int) arr.size();
        int one = accumulate(arr.begin(), arr.end(), 0);
        if (one % 3) return {-1, -1};
        if (!one) return {0, n - 1};
        int t = one / 3, suffix = 0;
        for (int i = n - 1; arr[i] == 0; i--) suffix++;
        int left, right;
        int i = 0;
        for (int cnt1 = 0, cnt0 = 0; cnt1 < t || cnt0 < suffix; i++) {
            if (arr[i]) cnt1++;
            else if (cnt1 == t && !arr[i]) cnt0++;
            if (cnt1 > t || cnt0 > suffix) return {-1, -1};
        }
        left = i - 1;
        for (int cnt1 = 0, cnt0 = 0; cnt1 < t || cnt0 < suffix; i++) {
            if (i == n) return {-1, -1};
            if (arr[i]) cnt1++;
            else if (cnt1 == t && !arr[i]) cnt0++;
            if (cnt1 > t || cnt0 > suffix) return {-1, -1};
        }
        right = i;
        int a = 0, b = left + 1, c = right;
        while (!arr[a]) a++;
        while (!arr[b]) b++;
        while (!arr[c]) c++;
        if (left - a != right - 1 - b || left - a != n - 1 - c) return {-1, -1};
        while (a <= left) {
            if (arr[a] != arr[b] || arr[a] != arr[c]) return {-1, -1};
            a++, b++, c++;
        }
        return {left, right};
    }
};