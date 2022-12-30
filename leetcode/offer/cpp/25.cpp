#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        auto head = new ListNode(0), dummy_head = head;
        while (l1 || l2) {
            if (l1 && l2) {
                if (l1->val < l2->val) {
                    head->next = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    head->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
            } else if (l1) {
                head->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                head->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            head = head->next;
        }
        return dummy_head->next;
    }
};