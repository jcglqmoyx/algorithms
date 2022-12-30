#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto a = headA, b = headB;
        while (headA != headB) {
            if (headA) headA = headA->next;
            else headA = a;
            if (headB) headB = headB->next;
            else headB = b;
        }
        return headA;
    }
};