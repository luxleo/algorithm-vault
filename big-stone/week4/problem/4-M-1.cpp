//
// Created by 5600G on 2026-11-13.
//
#include <bits/stdc++.h>
using namespace std;

string s;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastIO();
    cin >> s;

    for (int i=0; i<s.size(); i++)
    {
        if (i < s.size() - 1 && (s.substr(i,2) == "pi" || s.substr(i,2) == "ka"))
            i++;
        else if (i<s.size() - 2 && s.substr(i,3) == "chu")
            i+=2;
        else
        {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}
