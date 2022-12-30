struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return construct(head, nullptr);
    }

private:
    ListNode *get_mid(ListNode *start, ListNode *end) {
        ListNode *fast = start, *slow = start;
        while (fast != end && fast->next != end) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    TreeNode *construct(ListNode *start, ListNode *end) {
        if (start == end) return nullptr;
        ListNode *mid = get_mid(start, end);
        auto *root = new TreeNode(mid->val);
        root->left = construct(start, mid);
        root->right = construct(mid->next, end);
        return root;
    }
};