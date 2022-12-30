#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>> &courses) {
        sort(courses.begin(), courses.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        priority_queue<int> heap;
        int tot = 0;
        for (auto &course: courses) {
            tot += course[0];
            heap.push(course[0]);
            if (tot > course[1]) {
                int t = heap.top();
                tot -= t;
                heap.pop();
            }
        }
        return (int) heap.size();
    }
};