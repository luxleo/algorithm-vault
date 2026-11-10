//
// Created by 5600G on 2026-11-04.
//

#include <bits/stdc++.h>
using namespace std;

int N;
string str;

bool check(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(') st.push(c);
        else
        {
            if (!st.empty()) st.pop();
            else return false;
        }
    }

    // 반복문 순회후 나머지 처리
    return st.empty(); // 최후에는 비어있어야 모든 쌍이 맞아 떨어진것이다.
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> str;
        if (check(str)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
