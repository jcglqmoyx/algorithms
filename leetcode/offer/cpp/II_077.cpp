struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode *merge(ListNode *l, ListNode *r) {
        auto dummy = new ListNode(), cur = dummy;
        while (l || r) {
            if (l && r) {
                if (l->val < r->val) cur->next = l, l = l->next;
                else cur->next = r, r = r->next;
            } else if (l) {
                cur->next = l, l = l->next;
            } else {
                cur->next = r, r = r->next;
            }
            cur = cur->next;
        }
        auto res = dummy->next;
        delete dummy;
        return res;
    }

public:
    ListNode *sortList(ListNode *head) {
        if (!head) return nullptr;
        int n = 0;
        for (auto p = head; p; p = p->next) n++;
        for (int size = 1; size < n; size <<= 1) {
            auto dummy = new ListNode(-1, head), cur = head, last = dummy;
            for (int i = 0; i < n; i += size << 1) {
                auto p = cur, l = cur;
                for (int j = 0; j < size - 1; j++) {
                    if (p->next) p = p->next;
                }
                auto r = p->next;
                if (!p->next) {
                    last->next = merge(l, r);
                    break;
                }
                p->next = nullptr;
                p = r;
                for (int j = 0; j < size - 1; j++) {
                    if (p->next) p = p->next;
                    else break;
                }
                ListNode *next;
                if (p->next) next = p->next;
                p->next = nullptr;
                last->next = merge(l, r);
                while (last->next) last = last->next;
                cur = next;
            }
            head = dummy->next;
        }
        return head;
    }
};