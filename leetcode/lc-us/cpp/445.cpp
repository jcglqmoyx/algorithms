#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<int> arr1, arr2;
        while (l1) {
            arr1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            arr2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode *ans = nullptr;
        while (!arr1.empty() || !arr2.empty() || carry) {
            int x = arr1.empty() ? 0 : arr1.top();
            int y = arr2.empty() ? 0 : arr2.top();
            if (!arr1.empty()) arr1.pop();
            if (!arr2.empty()) arr2.pop();
            int sum = x + y + carry;
            carry = sum / 10;
            auto *cur = new ListNode(sum % 10);
            cur->next = ans;
            ans = cur;
        }
        return ans;
    }
};