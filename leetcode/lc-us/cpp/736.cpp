#include <bits/stdc++.h>

using namespace std;

class Solution {
    using MPSI = unordered_map<string, int>;

    int get_value(string &str, int &k, MPSI vars) {
        int value;
        if (str[k] == '-' || isdigit(str[k])) {
            int i = k + 1;
            while (isdigit(str[i])) i++;
            value = stoi(str.substr(k, i - k));
            k = i;
        } else if (str[k] != '(') {
            string name;
            while (str[k] != ' ' && str[k] != ')') name += str[k++];
            value = vars[name];
        } else {
            value = dfs(str, k, vars);
        }
        return value;
    }

    int dfs(string &str, int &k, MPSI vars) {
        int value = 0;
        k++;
        auto type = str.substr(k, 3);
        if (type == "let") {
            k += 4;
            while (str[k] != ')') {
                if (str[k] == '(' || str[k] == '-' || isdigit(str[k])) {
                    value = get_value(str, k, vars);
                    break;
                }
                string name;
                while (str[k] != ' ' && str[k] != ')') name += str[k++];
                if (str[k] == ')') {
                    value = vars[name];
                    break;
                }
                k++;
                vars[name] = get_value(str, k, vars);
                k++;
            }
        } else if (type == "add") {
            k += 4;
            int a = get_value(str, k, vars);
            k++;
            int b = get_value(str, k, vars);
            value = a + b;
        } else {
            k += 5;
            int a = get_value(str, k, vars);
            k++;
            int b = get_value(str, k, vars);
            value = a * b;
        }
        k++;
        return value;
    }

public:
    int evaluate(string expression) {
        int k = 0;
        return dfs(expression, k, MPSI());
    }
};