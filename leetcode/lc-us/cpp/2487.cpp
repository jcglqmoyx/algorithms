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
    ListNode *removeNodes(ListNode *head) {
        vector<ListNode *> v;
        while (head) {
            v.push_back(head);
            head = head->next;
        }
        int n = (int) v.size();
        int max_value = -1;
        auto dummy = new ListNode(), cur = dummy;
        for (int i = n - 1; i >= 0; i--) {
            if (v[i]->val < max_value) continue;
            max_value = v[i]->val;
            cur->next = v[i];
            cur = cur->next;
        }
        cur->next = nullptr;
        auto res = dummy->next;
        delete dummy;
        return reverse(res);
    }

    ListNode *reverse(ListNode *node) {
        ListNode *prev = nullptr;
        while (node) {
            auto next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};