//
// Created by 5600G on 2026-10-20.
//
#include <bits/stdc++.h>
using namespace std;

int N,t,seq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    while (t < N)
    {
        seq++;
        if (to_string(seq).find("666") != string::npos)
        {
            t++;
        }

    }

    cout << seq << "\n";
    return 0;
}
