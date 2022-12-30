#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumGroups(vector<int> &grades) {
        int n = (int) grades.size();
        return (int) ((sqrt(1 + (n << 3)) - 1) / 2);
    }
};