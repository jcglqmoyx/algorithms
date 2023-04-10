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
    vector<int> nextLargerNodes(ListNode *head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        auto n = v.size();
        vector<int> res(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && v[stk.top()] < v[i]) {
                if (v[stk.top()] < v[i]) res[stk.top()] = v[i];
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};