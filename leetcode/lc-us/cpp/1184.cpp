#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination) {
        if (start > destination) {
            return distanceBetweenBusStops(distance, destination, start);
        }
        int len1 = 0;
        for (int i = start; i < destination; i++) {
            len1 += distance[i];
        }
        int len2 = 0;
        for (int i = 0; i < start; i++) {
            len2 += distance[i];
        }
        for (int i = destination; i < distance.size(); i++) {
            len2 += distance[i];
        }
        return min(len1, len2);
    }
};