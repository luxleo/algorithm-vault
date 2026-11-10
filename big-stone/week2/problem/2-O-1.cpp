//
// Created by 5600G on 2026-11-04.
//
#include <bits/stdc++.h>
using namespace std;

string str;

bool check(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[') st.push(c);
        else
        {
            if (c == ')')
            {
                if (st.empty() || st.top() != '(') return false;
                st.pop();
            } else
            {
                if (st.empty() || st.top() != '[') return false;
                st.pop();
            }
        }
    }
    return st.empty();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;
    do
    {
        if (check(str)) cout << "yes\n";
        else cout << "no\n";
        cin >> str;
    } while (str != ".");
    return 0;
}
