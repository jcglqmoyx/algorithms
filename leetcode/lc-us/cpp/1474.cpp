struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteNodes(ListNode *head, int m, int n) {
        auto res = head;
        while (head) {
            for (int i = 0; i < m - 1 && head; i++) {
                head = head->next;
            }
            if (!head) break;
            auto temp = head->next;
            for (int j = 0; j < n && temp; j++) {
                temp = temp->next;
            }
            head->next = temp;
            head = temp;
        }
        return res;
    }
};