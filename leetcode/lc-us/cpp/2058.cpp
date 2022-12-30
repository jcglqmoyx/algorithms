#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        vector<int> v;
        while (head) v.push_back(head->val), head = head->next;
        int n = (int) v.size();
        if (n < 3) return {-1, -1};
        const int INF = 1e6;
        int mn = INF, mx = -INF;
        int start = -1, prev, cnt = 0;
        for (int i = 1; i < n - 1; i++) {
            if (v[i] > v[i - 1] && v[i] > v[i + 1] || v[i] < v[i - 1] && v[i] < v[i + 1]) {
                if (start == -1) start = i;
                else mn = min(mn, i - prev), mx = i - start;
                prev = i;
                cnt++;
            }
        }
        vector<int> res;
        if (start != -1 && cnt >= 2) res = {mn, mx};
        else res = {-1, -1};
        return res;
    }
};