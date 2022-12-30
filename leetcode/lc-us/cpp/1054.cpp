#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes) {
        int n = (int) barcodes.size();
        unordered_map<int, int> cnt;
        for (int b: barcodes) cnt[b]++;
        sort(barcodes.begin(), barcodes.end(), [&](int a, int b) {
            if (cnt[a] == cnt[b]) return a < b;
            else return cnt[a] > cnt[b];
        });
        vector<int> res(n);
        int index = 0;
        for (int i = 0; i < n; i += 2) {
            res[i] = barcodes[index];
            index++;
        }
        for (int j = 1; j < n; j += 2) {
            res[j] = barcodes[index];
            index++;
        }
        return res;
    }
};