#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
        unordered_map<int, int> cnt;
        for (int e: arr) cnt[e]++;
        priority_queue<int, vector<int>, greater<>> heap;
        for (auto &[_, v]: cnt) {
            heap.push(v);
        }
        while (k) {
            int t = heap.top();
            heap.pop();
            k -= t;
            if (k < 0) return (int) heap.size() + 1;
        }
        return (int) heap.size();
    }
};