//
// Created by 이동한 on 2025. 1. 22..
//
#include <bits/stdc++.h>
using namespace std;

/**
 *
 * @see https://www.acmicpc.net/problem/4949
 */
string dat;
void solve() {
    stack<char> st;
    char cur;
    for (int i=0; i<dat.size(); i++) {
        cur = dat[i];
        if (cur == ')') {
            if (st.size() && st.top() == '(') st.pop();
            else {
                cout << "no" << "\n";
                return;
            }
        }
        else if (cur == ']') {
            if (st.size() && st.top() == '[') st.pop();
            else {
                cout << "no" << "\n";
                return;
            }
        }
        if (cur == '(' || cur == '[') st.push(cur);
    }
    if (st.size()) cout << "no" << "\n";
    else cout << "yes" << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true) {
        getline(cin, dat);
        if (dat == ".") break;
        solve();
    }
    return 0;
}
