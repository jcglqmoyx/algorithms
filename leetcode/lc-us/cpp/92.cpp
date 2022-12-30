struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        auto dummy = new ListNode(0, head);
        head = dummy;
        for (int i = 1; i < m; i++) head = head->next;
        auto l = head->next;
        auto temp = head;
        for (int i = 0; i < n - m; i++) head = head->next;
        auto r = head->next;
        auto r_next = r->next;
        r->next = nullptr;
        l = reverse(l);
        temp->next = l;
        while (l && l->next) l = l->next;
        l->next = r_next;
        return dummy->next;
    }

    ListNode *reverse(ListNode *node) {
        ListNode *prev = nullptr;
        while (node) {
            auto *next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};