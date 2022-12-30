#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        unordered_map<string, int> map;
        for (int i = 0; i < list2.size(); i++) {
            map[list2[i]] = i;
        }
        int min_index_sum = 2000;
        vector<string> restaurants;
        for (int i = 0; i < list1.size(); i++) {
            if (map.count(list1[i])) {
                if (i + map[list1[i]] < min_index_sum) {
                    min_index_sum = i + map[list1[i]];
                    if (!restaurants.empty()) {
                        restaurants.clear();
                    }
                    restaurants.push_back(list1[i]);
                } else if (i + map[list1[i]] == min_index_sum) {
                    restaurants.push_back(list1[i]);
                }
            }
        }
        return restaurants;
    }
};