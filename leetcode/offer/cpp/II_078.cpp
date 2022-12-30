#include <bits/stdc++.h>

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto dummy = new ListNode, head = dummy;
        priority_queue<ListNode *, vector<ListNode *>, cmp> heap;
        for (auto &list: lists) heap.push(list);
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            if (!t) continue;
            auto next = t->next;
            t->next = nullptr;
            head->next = t;
            head = head->next;
            if (next) heap.push(next);
        }
        return dummy->next;
    }

private:
    struct cmp {
        bool operator()(const ListNode *a, const ListNode *b) const {
            if (!a) return true;
            if (!b) return false;
            return a->val > b->val;
        }
    };
};