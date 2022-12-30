struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        int len = get_length(head);
        auto *first = head;
        for (int i = 0; i < len / 2 - 1; i++) head = head->next;
        auto *second = head->next;
        head->next = nullptr;
        second = reverse(second);
        while (first && second) {
            if (first->val != second->val) return false;
            first = first->next, second = second->next;
        }
        return true;
    }

private:
    int get_length(ListNode *node) {
        int len = 0;
        while (node) {
            len++;
            node = node->next;
        }
        return len;
    }

    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr;
        while (head) {
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};