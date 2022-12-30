struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next) return head;
        ListNode *dummy = head;
        int len = 1;
        while (dummy->next) {
            len++;
            dummy = dummy->next;
        }
        dummy->next = head;
        for (int i = 0; i < len - k % len - 1; i++) {
            head = head->next;
        }
        ListNode *ans = head->next;
        head->next = nullptr;
        return ans;
    }
};