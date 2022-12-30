#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct Item {
        int coefficient;
        multiset<string> vars;

        bool operator<(const Item &t) const {
            if (vars.size() != t.vars.size()) return vars.size() > t.vars.size();
            return vars < t.vars;
        }

        bool operator==(const Item &t) const {
            return vars == t.vars;
        }

        string convert_to_string() {
            string res = to_string(coefficient);
            for (auto &var: vars) res += '*' + var;
            return res;
        }
    };

    unordered_map<string, int> value;
    stack<vector<Item>> num;
    stack<char> op;

    static vector<Item> add(vector<Item> a, vector<Item> b, int sign) {
        vector<Item> res;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                Item t{a[i].coefficient + b[j].coefficient * sign, a[i].vars};
                if (t.coefficient) res.push_back(t);
                i++, j++;
            } else if (a[i] < b[j]) {
                res.push_back(a[i++]);
            } else {
                res.push_back({b[j].coefficient * sign, b[j].vars}), j++;
            }
        }
        while (i < a.size()) res.push_back(a[i++]);
        while (j < b.size()) res.push_back({b[j].coefficient * sign, b[j].vars}), j++;
        return res;
    }

    static vector<Item> mul(const vector<Item> &a, const vector<Item> &b) {
        vector<Item> res;
        for (auto &x: a) {
            vector<Item> items;
            for (auto &y: b) {
                Item t{x.coefficient * y.coefficient, x.vars};
                for (auto &v: y.vars) t.vars.insert(v);
                items.push_back(t);
            }
            res = add(res, items, 1);
        }
        return res;
    }

    void eval() {
        auto b = num.top();
        num.pop();
        auto a = num.top();
        num.pop();
        auto c = op.top();
        op.pop();
        vector<Item> x;
        if (c == '+') x = add(a, b, 1);
        else if (c == '-') x = add(a, b, -1);
        else x = mul(a, b);
        num.push(x);
    }

    vector<Item> calc(string &str) {
        unordered_map<char, int> pr{{'+', 1},
                                    {'-', 1},
                                    {'*', 2}};
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') continue;
            if (str[i] >= 'a' && str[i] <= 'z' || isdigit(str[i])) {
                vector<Item> items;
                if (str[i] >= 'a' && str[i] <= 'z') {
                    string var;
                    int j = i;
                    while (j < str.size() && str[j] >= 'a' && str[j] <= 'z') var += str[j++];
                    i = j - 1;
                    if (value.count(var)) {
                        if (value[var]) items.push_back({value[var], {}});
                    } else {
                        items.push_back({1, {var}});
                    }
                } else {
                    int x = 0, j = i;
                    while (j < str.size() && isdigit(str[j])) x = x * 10 + str[j++] - '0';
                    i = j - 1;
                    if (x) items.push_back({x, {}});
                }
                num.push(items);
            } else if (str[i] == '(') {
                op.push(str[i]);
            } else if (str[i] == ')') {
                while (op.top() != '(') eval();
                op.pop();
            } else {
                while (!op.empty() && op.top() != '(' && pr[op.top()] >= pr[str[i]]) eval();
                op.push(str[i]);
            }
        }
        while (!op.empty()) eval();
        return num.top();
    }

public:
    vector<string> basicCalculatorIV(string expression, vector<string> &evalvars, vector<int> &evalints) {
        for (int i = 0; i < evalvars.size(); i++) value[evalvars[i]] = evalints[i];
        auto t = calc(expression);
        vector<string> res;
        res.reserve(t.size());
        for (auto &item: t) res.push_back(item.convert_to_string());
        return res;
    }
};