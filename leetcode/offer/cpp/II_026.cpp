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
    void reorderList(ListNode *head) {
        vector<ListNode *> nodes;
        while (head) {
            nodes.push_back(head);
            head = head->next;
        }
        int l = 0, r = (int) nodes.size() - 1;
        vector<ListNode *> res;
        int n = (int) nodes.size();
        res.reserve(n);
        while (l <= r) {
            res.push_back(nodes[l++]);
            if (res.size() == n) break;
            res.push_back(nodes[r--]);
        }
        for (int i = 0; i < n - 1; i++) res[i]->next = res[i + 1];
        res.back()->next = nullptr;
        head = res[0];
    }
};