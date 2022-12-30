#include <vector>
#include <queue>

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
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto dummy = new ListNode(), head = dummy;
        priority_queue<ListNode *, vector<ListNode *>, cmp> heap;
        for (auto node: lists) {
            if (node) heap.push(node);
        }
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            head->next = t;
            head = head->next;
            if (t->next) {
                heap.push(t->next);
            }
        }
        return dummy->next;
    }
};