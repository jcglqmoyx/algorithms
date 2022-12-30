#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);
        int candy = 1;
        while (candies) {
            for (int i = 0; i < num_people; i++) {
                if (candies > candy) {
                    res[i] += candy;
                    candies -= candy;
                } else {
                    res[i] += candies;
                    return res;
                }
                candy++;
            }
        }
        return res;
    }
};