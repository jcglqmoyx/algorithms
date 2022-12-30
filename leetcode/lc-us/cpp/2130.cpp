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
    int pairSum(ListNode *head) {
        int res = INT32_MIN;
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        int n = (int) v.size();
        for (int i = 0; i < n / 2; i++) {
            res = max(res, v[i] + v[n - 1 - i]);
        }
        return res;
    }
};