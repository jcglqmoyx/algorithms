#include <bits/stdc++.h>

using namespace std;

/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node() {};

    virtual int evaluate() const {
        if (val == "+") {
            return left->evaluate() + right->evaluate();
        } else if (val == "-") {
            return left->evaluate() - right->evaluate();
        } else if (val == "*") {
            return left->evaluate() * right->evaluate();
        } else if (val == "/") {
            return left->evaluate() / right->evaluate();
        } else {
            return stoi(val);
        }
    }

protected:
    // define your fields here
    string val;
    Node *left{}, *right{};

    friend class TreeBuilder;
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node *buildTree(vector<string> &postfix) {
        stack<Node *> stk;
        Node *node;
        for (auto &s: postfix) {
            node = new Node();
            node->val = s;
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                node->right = stk.top();
                stk.pop();
                node->left = stk.top();
                stk.pop();
            }
            stk.push(node);
        }
        return stk.top();
    }
};