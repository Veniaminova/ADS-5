// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int p_o(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

std::string infx2pstfx(std::string inf) {
    std::string res = "";
    TStack <char, 100> st;
    for (int i = 0; i < inf.size(); ++i) {
        if (isdigit(inf[i])) {
            while (isdigit(inf[i]) && i != inf.size()) {
                res += inf[i];
                ++i;
            }
            --i;
            res += " ";
            continue;
        } else if (inf[i] == '(') {
            st.push('(');
        } else if (inf[i] == ')') {
            while (st.top() != '(') {
                res += st.top();
                res += " ";
                st.pop();
            }
            st.pop();
        } else if (p_o(inf[i]) != -1) {
            int cur_priority = p_o(inf[i]);
            while (!st.empty() && cur_priority <= p_o(st.top())) {
                res += st.top();
                res += " ";
                st.pop();
            }
            st.push(inf[i]);
        }
    }
    while (!st.empty()) {
        res += st.top();
        res += " ";
        st.pop();
    }
    return res;
}

int eval(std::string post) {
    int a = 0;
    int b = 0;
    bool flag_first = true;
    for (int i = 0; i < post.size(); ++i) {
        if (isspace(post[i])) continue;
        if (isdigit(post[i])) {
            int t = 0;
            while (isdigit(post[i]) && i != post.size()) {
                t *= 10;
                t += post[i] - '0';
                ++i;
            }
            if (flag_first) {
                a = t;
                flag_first = false;
            } else {
                b = t;
            }
        } else {
            if (post[i] == '+') a = a + b;
            if (post[i] == '-') a = a - b;
            if (post[i] == '*') a = a * b;
            if (post[i] == '/') a = a / b;
        }
    }
    return a;
}
