struct PolyNode {
    int coefficient, power;
    PolyNode *next;

    PolyNode() : coefficient(0), power(0), next(nullptr) {};

    PolyNode(int x, int y) : coefficient(x), power(y), next(nullptr) {};

    PolyNode(int x, int y, PolyNode *next) : coefficient(x), power(y), next(next) {};
};

class Solution {
public:
    PolyNode *addPoly(PolyNode *poly1, PolyNode *poly2) {
        auto *dummy = new PolyNode(), *head = dummy;
        while (poly1 || poly2) {
            if (poly1 && poly2) {
                if (poly1->power == poly2->power) {
                    int coefficient = poly1->coefficient + poly2->coefficient;
                    if (coefficient) {
                        head->next = new PolyNode(coefficient, poly1->power);
                        head = head->next;
                    }
                    poly1 = poly1->next, poly2 = poly2->next;
                } else {
                    if (poly1->power > poly2->power) {
                        head->next = new PolyNode(poly1->coefficient, poly1->power);
                        poly1 = poly1->next;
                    } else {
                        head->next = new PolyNode(poly2->coefficient, poly2->power);
                        poly2 = poly2->next;
                    }
                    head = head->next;
                }
            } else if (poly1) {
                head->next = poly1;
                break;
            } else {
                head->next = poly2;
                break;
            }
        }
        return dummy->next;
    }
};