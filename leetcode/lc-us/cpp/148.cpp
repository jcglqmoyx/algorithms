struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    int length(ListNode *head) {
        ListNode *dummy_head = head;
        int len = 0;
        while (dummy_head) {
            len++;
            dummy_head = dummy_head->next;
        }
        return len;
    }

    ListNode *merge(ListNode *head1, ListNode *head2) {
        auto *dummy_head = new ListNode(0), *head = dummy_head;
        while (head1 || head2) {
            if (head1 && head2) {
                if (head1->val < head2->val) {
                    head->next = head1;
                    head1 = head1->next;
                } else {
                    head->next = head2;
                    head2 = head2->next;
                }
            } else if (head1) {
                head->next = head1;
                head1 = head1->next;
            } else {
                head->next = head2;
                head2 = head2->next;
            }
            head = head->next;
        }
        return dummy_head->next;
    }

public:
    ListNode *sortList(ListNode *head) {
        if (!head) return nullptr;
        int len = length(head);
        auto *dummy_head = new ListNode(0, head);
        for (int size = 1; size < len; size <<= 1) {
            ListNode *prev = dummy_head, *cur = dummy_head->next;
            while (cur) {
                ListNode *head1 = cur;
                for (int i = 1; i < size && cur->next; i++) {
                    cur = cur->next;
                }

                auto head2 = cur->next;
                cur->next = nullptr;
                cur = head2;
                for (int i = 1; i < size && cur && cur->next; i++) {
                    cur = cur->next;
                }

                ListNode *next = nullptr;
                if (cur) {
                    next = cur->next;
                    cur->next = nullptr;
                }
                auto merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next) prev = prev->next;
                cur = next;
            }
        }
        return dummy_head->next;
    }
};