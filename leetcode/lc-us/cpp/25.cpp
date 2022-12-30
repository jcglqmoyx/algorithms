struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        auto *dummy = new ListNode(-1, head);
        for (auto p = dummy;;) {
            auto q = p;
            for (int i = 0; i < k && q; i++) q = q->next;
            if (!q) break;
            auto a = p->next, b = a->next;
            for (int i = 0; i < k - 1; i++) {
                auto next = b->next;
                b->next = a;
                a = b, b = next;
            }
            auto next = p->next;
            p->next = a, next->next = b;
            p = next;
        }
        return dummy->next;
    }
};