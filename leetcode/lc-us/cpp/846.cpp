#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        int n = (int) hand.size();
        if (n % groupSize) return false;
        unordered_map<int, int> cnt;
        for (int num: hand) cnt[num]++;
        sort(hand.begin(), hand.end());
        for (int num: hand) {
            if (cnt.find(num) == cnt.end()) continue;
            for (int i = num; i < num + groupSize; i++) {
                if (cnt.find(i) == cnt.end()) return false;
                cnt[i]--;
                if (cnt[i] == 0) cnt.erase(i);
            }
        }
        return true;
    }
};