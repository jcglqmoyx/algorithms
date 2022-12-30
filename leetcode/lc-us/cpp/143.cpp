struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head) return;
        ListNode *mid = get_mid(head);
        ListNode *right = mid->next;
        mid->next = nullptr;
        right = reversed(right);
        ListNode *left = head;
        merge(left, right);
    }

private:
    ListNode *get_mid(ListNode *head) {
        auto fast = head, slow = head;
        fast = fast->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *reversed(ListNode *head) {
        ListNode *prev = nullptr;
        while (head) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        auto dummy = new ListNode(0), head = dummy;
        while (l1 || l2) {
            if (l1 && l2) {
                dummy->next = l1;
                dummy = dummy->next;
                l1 = l1->next;
                dummy->next = l2;
                dummy = dummy->next;
                l2 = l2->next;
            } else if (l1) {
                dummy->next = l1;
                break;
            } else {
                dummy->next = l2;
                break;
            }
        }
        return head->next;
    }
};