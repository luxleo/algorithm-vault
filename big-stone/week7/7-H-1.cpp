//
// Created by 5600G on 2026-11-20.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXK = 10001;
const int INF = 1e9;
int n,k,a[MAXK],temp;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastIO();
    cin >> n >> k;
    a[0] = 1;

    for (int i=0; i<n; i++)
    {
        cin >> temp;
        if (temp >= MAXK) continue;
        for (int j=temp; j<=k; j++)
            a[j] += a[j-temp];

    }
    cout << a[k] << '\n';
    return 0;
}
