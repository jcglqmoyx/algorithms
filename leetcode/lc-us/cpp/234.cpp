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
        auto temp = new ListNode(0), dummy = head, cp = temp;
        while (dummy) {
            temp->next = new ListNode(dummy->val);
            temp = temp->next;
            dummy = dummy->next;
        }
        auto reversed_list = reverse(head);
        while (reversed_list) {
            if (cp->next->val != reversed_list->val) {
                return false;
            }
            cp = cp->next;
            reversed_list = reversed_list->next;
        }
        return true;
    }

    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr;
        auto cur = head;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};