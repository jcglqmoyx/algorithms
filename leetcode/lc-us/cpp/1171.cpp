#include <unordered_map>

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
    ListNode *removeZeroSumSublists(ListNode *head) {
        auto dummy = new ListNode(0, head);
        int sum = 0;
        unordered_map<int, ListNode *> hash;
        for (auto cur = dummy; cur; cur = cur->next) {
            sum += cur->val;
            hash[sum] = cur;
        }
        sum = 0;
        for (auto cur = dummy; cur; cur = cur->next) {
            sum += cur->val;
            cur->next = hash[sum]->next;
        }
        return dummy->next;
    }
};