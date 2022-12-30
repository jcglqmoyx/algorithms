#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int> &candies) {
        unordered_set<int> set;
        for (int candy: candies) {
            set.insert(candy);
        }
        return (int) min(candies.size() / 2, set.size());
    }
};