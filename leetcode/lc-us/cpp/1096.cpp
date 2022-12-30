#include <bits/stdc++.h>

using namespace std;

using SS = unordered_set<string>;

SS add(SS &A, SS &B) {
    SS C(A.begin(), A.end());
    for (auto &s: B) {
        if (!s.empty()) {
            C.insert(s);
        }
    }
    return C;
}

SS mul(SS &A, SS &B) {
    SS C;
    for (auto &x: A) {
        for (auto &y: B) {
            C.insert(x + y);
        }
    }
    return C;
}

class Solution {
    SS dfs(string &expression, int &k) {
        SS A, B;
        B.insert("");
        while (k < expression.size() && expression[k] != '}') {
            if (expression[k] == ',') {
                k++;
                continue;
            } else if (expression[k] == '{') {
                bool is_add = true;
                if (!k || expression[k - 1] != ',') is_add = false;
                k++;
                auto C = dfs(expression, k);
                k++;
                if (is_add) {
                    A = add(A, B);
                    B = move(C);
                } else {
                    B = mul(B, C);
                }
            } else {
                bool is_add = true;
                if (!k || expression[k - 1] != ',') is_add = false;
                string s;
                while (isalpha(expression[k])) {
                    s.push_back(expression[k++]);
                }
                SS C;
                C.insert(s);
                if (is_add) {
                    A = add(A, B);
                    B = move(C);
                } else {
                    B = mul(B, C);
                }
            }
        }
        return add(A, B);
    }

public:
    vector<string> braceExpansionII(string expression) {
        int k = 0;
        auto t = dfs(expression, k);
        vector<string> res(t.begin(), t.end());
        sort(res.begin(), res.end());
        return res;
    }
};