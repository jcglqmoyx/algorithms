#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int> &gifts, int k) {
        long long res = 0;
        priority_queue<int> heap;
        for (int gift: gifts) {
            heap.push(gift);
            res += gift;
        }
        while (k--) {
            int t = heap.top();
            heap.pop();
            int left = (int) sqrt(t);
            res -= t - left;
            heap.push(left);
        }
        return res;
    }
};