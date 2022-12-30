#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>> &customers) {
        int n = (int) customers.size();
        double waiting_time = 0.0;
        int start = customers[0][0];
        for (vector<int> &customer: customers) {
            if (start > customer[0]) {
                waiting_time += start - customer[0] + customer[1];
                start += customer[1];

            } else {
                waiting_time += customer[1];
                start = customer[0] + customer[1];
            }
        }
        return waiting_time / n;
    }
};