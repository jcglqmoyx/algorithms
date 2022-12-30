class MyLinkedList {
    struct Node {
        int val;
        Node *next;

        Node() : val(0), next() {};

        Node(int _val) : val(_val), next() {};
    };

    Node *head;
public:
    MyLinkedList() {
        head = new Node();
    }

    int get(int index) {
        auto t = head;
        while (index >= 0) {
            t = t->next;
            if (!t) return -1;
            index--;
        }
        return t->val;
    }

    void addAtHead(int val) {
        auto t = new Node(val);
        auto next = head->next;
        t->next = next;
        head->next = t;
    }

    void addAtTail(int val) {
        auto t = head;
        while (t->next) {
            t = t->next;
        }
        t->next = new Node(val);
    }

    void addAtIndex(int index, int val) {
        auto t = head;
        while (index >= 0) {
            index--;
            if (index == -1) {
                auto next = t->next;
                auto node = new Node(val);
                node->next = next;
                t->next = node;
                return;
            } else {
                t = t->next;
                if (!t) return;
            }
        }
    }

    void deleteAtIndex(int index) {
        auto t = head;
        while (index > 0) {
            index--;
            t = t->next;
            if (!t->next) return;
        }
        if (t->next) {
            auto next = t->next->next;
            auto removed = t->next;
            t->next = next;
            delete removed;
        }
    }
};