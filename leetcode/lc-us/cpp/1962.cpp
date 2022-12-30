#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int> &piles, int k) {
        priority_queue<int> heap;
        int sum = 0;
        for (int pile: piles) {
            heap.push(pile);
            sum += pile;
        }
        int s = 0;
        for (int i = 0; i < k; i++) {
            int t = heap.top();
            heap.pop();
            s += t / 2;
            heap.push(t - t / 2);
        }
        return sum - s;
    }
};