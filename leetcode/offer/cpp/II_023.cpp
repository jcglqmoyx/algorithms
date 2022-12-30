#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p = headA, q = headB;
        bool flag = false;
        while (p != q) {
            p = p->next, q = q->next;
            if (!p) {
                if (flag) return nullptr;
                p = headB;
                flag = true;
            }
            if (!q) q = headA;
        }
        return p;
    }
};